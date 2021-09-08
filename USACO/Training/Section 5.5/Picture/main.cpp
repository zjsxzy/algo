/*
ID: frankzh1
TASK: picture
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int maxn = 20005;
struct Segment {
    int l, r, h, s;
    Segment(int l, int r, int h, int s) {
        this->l = l;
        this->r = r;
        this->h = h;
        this->s = s;
    }
    bool operator < (const Segment& p) {
        if (h != p.h) return h < p.h;
        else return s > p.s;
    }
};
struct SegTree {

    bool lbd[maxn << 2], rbd[maxn << 2]; //标记这个节点的左右两个端点是否被覆盖（0表示没有，1表示有）
    int cnt[maxn << 2]; //表示这个区间被重复覆盖了几次
    int len[maxn << 2]; //这个区间被覆盖的长度
    int numseg[maxn << 2]; //这个区间有多少条线段（这个区间被多少条线段覆盖）

	int lson(int rt) {return rt << 1;}
	int rson(int rt) {return rt << 1 | 1;}

    void pushUp(int rt, int l, int r) {
        if (cnt[rt]) { //整个区间被覆盖
            //cout << l << " " << r << " " << cnt[rt] << endl;
            lbd[rt] = rbd[rt] = 1;
            len[rt] = r - l + 1;
            //cout << rt << " " << len[rt] << endl;
            numseg[rt] = 2; //每条线段有两个端点
        } else if (l == r) { //这是一个点而不是一条线段
            len[rt] = numseg[rt] = lbd[rt] = rbd[rt] = 0;
        } else { //是一条没有整个区间被覆盖的线段，合并左右子的信息
            lbd[rt] = lbd[lson(rt)];
            rbd[rt] = rbd[rson(rt)];
            len[rt] = len[lson(rt)] + len[rson(rt)];
            numseg[rt] = numseg[lson(rt)] + numseg[rson(rt)];
            if (lbd[rson(rt)] && rbd[lson(rt)]) numseg[rt] -= 2; //如果左子的右端点和右子的左端点都被覆盖了即两条线重合
        }
    }

    void update(int L, int R, int c, int l, int r, int rt) {
        //cout << L << " " << R << " " << l << " " << r << endl;
        if (L <= l && r <= R) {
            cnt[rt] += c;
            pushUp(rt, l, r);
            return;
        }
        int mid = (l + r) >> 1;
        if (L <= mid) update(L, R, c, l, mid, lson(rt));
        if (R > mid) update(L, R, c, mid + 1, r, rson(rt));
        pushUp(rt, l, r);
    }

    void build() {
        memset(cnt, 0, sizeof(cnt));
        memset(numseg, 0, sizeof(numseg));
        memset(len, 0, sizeof(len));
        memset(lbd, 0, sizeof(lbd));
        memset(rbd, 0, sizeof(rbd));
    }

}tree;

void solve() {
    int n;
    cin >> n;
    vector<Segment> seg;
    int lbound = 10000, rbound = -10000;
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        lbound = min(lbound, x1);
        rbound = max(rbound, x2);
        seg.emplace_back(x1, x2, y1, 1);
        seg.emplace_back(x1, x2, y2, -1);
    }
    sort(seg.begin(), seg.end());
    tree.build();
    int res = 0, prev = 0;
    for (int i = 0; i < seg.size(); i++) {
        tree.update(seg[i].l, seg[i].r - 1, seg[i].s, lbound, rbound - 1, 1);
        if (i + 1 < seg.size()) res += tree.numseg[1] * (seg[i + 1].h - seg[i].h); //竖线的长度 = 【下一条即将被扫到的横线的高度 - 现在扫到的横线的高度】* 竖线的数量
        res += abs(tree.len[1] - prev);
        //cout << i << " " << tree.len[1] << " " << prev << " " << tree.numseg[1] << " " << res << endl;
        prev = tree.len[1];
    }
    res += abs(tree.len[1] - prev);
    cout << res << endl;
}

int main() {
    freopen("picture.in", "r", stdin);
    freopen("picture.out", "w", stdout);
    solve();
    return 0;
}

