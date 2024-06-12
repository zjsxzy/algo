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

// index from 0
struct Fenwick{
    using T = LL;
    vector<T> tree;
    int n;
    Fenwick() {}
    Fenwick(int _n) {
        n = _n;
        tree.assign(n, 0);
    }
    void upd(int pos, T val) {
        for (; pos < n; pos |= pos + 1) {
            tree[pos] += val;
        }
    }
    T get(int r) {
        T ans = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1) {
            ans += tree[r];
        }
        return ans;
    }
    T get(int l, int r) {
        if (l > r) return 0;
        return get(r) - get(l - 1);
    }
};

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
    vector<LL> ans(q);
    Fenwick c(n + 1), kc(n + 1), kkc(n + 1); // a_i, a_i * i, a_i * i * i
    // 三个树状数组单点更新
    auto add = [&](int p, LL x) {
        c.upd(p, x);
        kc.upd(p, x * p);
        kkc.upd(p, x * p * p);
    };
    // 区间[l,r]增加首项伟v，公差为d的等差数列
    auto upd = [&](int l, int r, LL v, LL d) {
        add(l, v);
        add(l + 1, d - v);
        add(r + 1, -(v + d * (r - l + 1)));
        add(r + 2, (v + d * (r - l)));
    };
    // 更新区间[1,len]
    auto calc = [&](int len, int coef) {
        if (coef == 1) upd(1, len, len, -1);
        if (coef == -1) upd(1, len, -len, 1);
    };
    // 统计a数组[1,r]的区间和
    auto get_sum = [&](LL r) {
        LL s = (r + 1) * (r + 2) * c.get(r);
        s -= (2 * r + 3) * kc.get(r);
        s += kkc.get(r);
        return s / 2;
    };
    // 查询区间[l,r]的和
    auto range_sum = [&](int l, int r) {
        return get_sum(r) - get_sum(l - 1);
    };
    for (auto v: vec) {
        int val = v.first, idx = v.second.first;
        int l = v.second.second.first, r = v.second.second.second;
        if (idx >= q) {
            idx -= q;
            b[idx] = val;
            if (idx - 1 >= 0 && b[idx - 1] != 0) {
                calc(dsu.siz[dsu.root(idx - 1)], -1);
                dsu.unite(idx - 1, idx);
            }
            if (idx + 1 < n && b[idx + 1] != 0) {
                calc(dsu.siz[dsu.root(idx + 1)], -1);
                dsu.unite(idx, idx + 1);
            }
            calc(dsu.siz[dsu.root(idx)], 1);
        } else {
            ans[idx] = range_sum(l, r);
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