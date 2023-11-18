#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

// index from 0
struct Fenwick{
    using T = int;
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
    LL m;
    cin >> n >> m;
    vector<int> dfn(n), siz(n);
    vector<vector<pair<int, LL>>> g(n);
    vector<LL> dep(n);
    for (int i = 1; i < n; i++) {
        int p;
        LL d;
        cin >> p >> d;
        p--;
        g[i].emplace_back(p, d);
        g[p].emplace_back(i, d);
    }
    int cnt = 0;
    function<void(int, int, LL)> dfs = [&](int u, int fa, LL d) {
        dep[u] = d;
        dfn[u] = cnt++;
        siz[u]++;
        for (auto [v, w]: g[u]) {
            if (v == fa) continue;
            dfs(v, u, d + w);
            siz[u] += siz[v];
        }
    };
    dfs(0, -1, 0);
    vector<pair<LL, int>> d;
    for (int i = 0; i < n; i++) d.emplace_back(dep[i], i);
    sort(d.begin(), d.end());
    Fenwick tree(n);
    vector<int> ans(n);
    for (int i = 0, j = 0; i < n; i++) {
        while (j < n && d[j].first <= d[i].first + m) {
            tree.upd(dfn[d[j].second], 1);
            j++;
        }
        ans[d[i].second] = tree.get(dfn[d[i].second], dfn[d[i].second] + siz[d[i].second] - 1);
        tree.upd(dfn[d[i].second], -1);
    }
    for (int i = 0; i < n; i++) cout << ans[i] << endl;
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