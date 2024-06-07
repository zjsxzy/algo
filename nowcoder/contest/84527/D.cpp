#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

struct union_find{
    int N;
    vector<int> par, siz;
    union_find(int n) : N(n){
        par.resize(N);
        siz.resize(N, 1);
        for(int i=0; i<N; i++) par[i] = i;
    }
    int root(int X){
        if(par[X] == X) return X;
        return par[X] = root(par[X]);
    }
    bool same(int X, int Y){
        return root(X) == root(Y);
    }
    void unite(int X, int Y){
        X = root(X);
        Y = root(Y);
        if(X == Y) return;
        if(siz[Y] < siz[X]) std::swap(X, Y);
        par[X] = Y;
        siz[Y] += siz[X];
        siz[X] = 0;
    }
};

const int MAXN = 100000 + 5;
LL val[MAXN];
struct SegTree {

	LL sum[MAXN << 2], add[MAXN << 2], put[MAXN << 2];

	int lson(int rt) {
		return rt << 1;
	}

	int rson(int rt) {
		return rt << 1 | 1;
	}

	void pushUp(int rt) {
		sum[rt] = sum[lson(rt)] + sum[rson(rt)];
	}

	void pushDown(int rt, int m) {
		if (m == 1) return;
		if (put[rt] != -1) {
			put[lson(rt)] = put[rt];
			put[rson(rt)] = put[rt];
			add[lson(rt)] = 0;
			add[rson(rt)] = 0;
			sum[lson(rt)] = put[rt] * (m - (m >> 1));
			sum[rson(rt)] = put[rt] * (m >> 1);
			put[rt] = -1;
		}
		if (add[rt] != 0) {
			add[lson(rt)] += add[rt];
			add[rson(rt)] += add[rt];
			sum[lson(rt)] += add[rt] * (m - (m >> 1));
			sum[rson(rt)] += add[rt] * (m >> 1);
			add[rt] = 0;
		}
	}

	void build(int l, int r, int rt) {
		add[rt] = 0;
		put[rt] = -1;
		sum[rt] = 0;
		if (l == r) {
			sum[rt] = val[l];
			return;
		}
		int mid = (l + r) >> 1;
		build(l, mid, lson(rt));
		build(mid + 1, r, rson(rt));
		pushUp(rt);
	}

	void updateAdd(int L, int R, LL c, int l, int r, int rt) {
		pushDown(rt, r - l + 1);
		if (L <= l && r <= R) {
			add[rt] += c;
			sum[rt] += c * (r - l + 1);
			return;
		}
		int mid = (l + r) >> 1;
		if (L <= mid) updateAdd(L, R, c, l, mid, lson(rt));
		if (R > mid) updateAdd(L, R, c, mid + 1, r, rson(rt));
		pushUp(rt);
	}

	LL query(int L, int R, int l, int r, int rt) {
		if (L <= l && r <= R) {
			return sum[rt];
		}
		pushDown(rt, r - l + 1);
		int mid = (l + r) >> 1;
		LL res = 0;
		if (L <= mid) res += query(L, R, l, mid, lson(rt));
		if (mid < R) res += query(L, R, mid + 1, r, rson(rt));
		return res;
	}

}tree;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x: a) cin >> x;
    vector<pair<int, pair<int, pair<int, int>>>> vec;
    int q;
    cin >> q;
    for (int i = 0; i < n; i++) {
        vec.push_back({a[i], {q + i, {-1, -1}}});
    }
    for (int i = 0; i < q; i++) {
        int v, minl, maxl;
        cin >> v >> minl >> maxl;
        vec.push_back({v, {i, {minl, maxl}}});
    }
    sort(vec.rbegin(), vec.rend());
    vector<int> b(n);
    union_find dsu(n);
    memset(val, 0, sizeof(val));
    tree.build(1, n, 1);
    vector<LL> ans(q);
    for (auto v: vec) {
        int val = v.first, idx = v.second.first;
        int l = v.second.second.first, r = v.second.second.second;
        if (idx >= q) {
            idx -= q;
            b[idx] = val;
            if (idx - 1 >= 0 && b[idx - 1] != 0) {
                dsu.unite(idx - 1, idx);
                int sz = dsu.siz[dsu.root(idx)];
                tree.updateAdd(1, sz, 1, 1, n, 1);
            }
            if (idx + 1 < n && b[idx + 1] != 0) {
                int l = dsu.siz[dsu.root(idx + 1)];
                dsu.unite(idx, idx + 1);
                int r = dsu.siz[dsu.root(idx)];

            }
        } else {
            ans[idx] = tree.query(l, r, 1, n, 1);
        }
    }
    for (auto x: ans) cout << x << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}