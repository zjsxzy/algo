#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

// index from 0
struct Fenwick{
    vector<int> tree;
    int n;
    Fenwick() {}
    Fenwick(int _n) {
        n = _n;
        tree.assign(n, 0);
    }
    void upd(int pos, int val) {
        for (; pos < n; pos |= pos + 1) {
            tree[pos] += val;
        }
    }
    int get(int r) {
        int ans = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1) {
            ans += tree[r];
        }
        return ans;
    }
    int get(int l, int r) {
        if (l > r) return 0;
        return get(r) - get(l - 1);
    }
};
struct Query {
    int l, r, x, id, ans;
};

bool cmp1(const Query& a, const Query& b) {
    return a.x < b.x;
}
bool cmp2(const Query& a, const Query& b) {
    return a.id < b.id;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, vector<int>> pos;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pos[a[i]].push_back(i);
    }
    int q;
    cin >> q;
    vector<Query> que;
    for (int i = 0; i < q; i++) {
        int l, r, x;
        cin >> l >> r >> x;
        l--; r--;
        Query t;
        t.l = l; t.r = r; t.x = x; t.id = i;
        que.push_back(t);
    }
    sort(que.begin(), que.end(), cmp1);
    Fenwick tree(n);
    int x = que[0].x, j = 0;
    for (int i = 1; i < q; i++) {
        if (que[i].x != x) {
            for (auto p: pos[x]) {
                tree.upd(p, 1);
            }
            while (j != i) {
                que[j].ans = tree.get(que[j].l, que[j].r);
                j++;
            }
            for (auto p: pos[x]) {
                tree.upd(p, -1);
            }
            x = que[i].x;
        }
    }
    for (auto p: pos[x]) {
        tree.upd(p, 1);
    }
    while (j != q) {
        que[j].ans = tree.get(que[j].l, que[j].r);
        j++;
    }
    sort(que.begin(), que.end(), cmp2);
    for (int i = 0; i < q; i++) {
        cout << que[i].ans << endl;
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

