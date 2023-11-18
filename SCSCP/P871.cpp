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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for (int i = 1; i < n; i++) {
        int p;
        cin >> p;
        p--;
        g[i].push_back(p);
        g[p].push_back(i);
    }
    vector<int> x(n);
    for (int i = 0; i < n; i++) cin >> x[i];
    vector<int> dfn(n), siz(n);
    int cnt = 0;
    function<void(int, int)> dfs = [&](int u, int fa) {
        dfn[u] = cnt++;
        siz[u]++;
        for (auto v: g[u]) {
            if (v == fa) continue;
            dfs(v, u);
            siz[u] += siz[v];
        }
    };
    dfs(0, -1);
    vector<pair<int, int>> vec;
    for (int i = 0; i < n; i++) vec.emplace_back(x[i], i);
    sort(vec.begin(), vec.end());
    Fenwick tree(n);
    for (int i = 0; i < n; i++) tree.upd(i, 1);
    LL res = 0;
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         if (dfn[j] > dfn[i] && dfn[j] < dfn[i] + siz[i] && (LL)x[i] * x[j] <= m) res++;
    //     }
    // }
    for (int i = 0, j = n - 1; i < n; i++) {
        while (j >= 0 && (LL)vec[i].first * vec[j].first > m) {
            tree.upd(dfn[vec[j].second], -1);
            j--;
        }
        res += tree.get(dfn[vec[i].second] + 1, dfn[vec[i].second] + siz[vec[i].second] - 1);
    }
    cout << res << endl;
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