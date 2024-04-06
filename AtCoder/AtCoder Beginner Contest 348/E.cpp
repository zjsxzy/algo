#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> C(n);
    for (int i = 0; i < n; i++) cin >> C[i];
    vector<int> dep(n), dfn(n), siz(n);
    int cnt = 0;
    function<void(int, int, int)> dfs = [&](int u, int fa, int d) {
        dep[u] = d;
        dfn[u] = cnt++;
        siz[u]++;
        for (auto v: g[u]) {
            if (v == fa) continue;
            dfs(v, u, d + 1);
            siz[u] += siz[v];
        }
    };
    dfs(0, -1, 0);
    vector<LL> sum(n);
    for (int i = 0; i < n; i++) {
        sum[dfn[i]] = C[i];
    }
    for (int i = 1; i < n; i++) {
        sum[i] = sum[i - 1] + sum[i];
    }
    auto get_sum = [&](int i, int j) {
        if (i == 0) return sum[j];
        return sum[j] - sum[i - 1];
    };
    vector<LL> f(n);
    for (int i = 1; i < n; i++) {
        f[0] += (LL)dep[i] * C[i];
    }
    function<void(int, int)> calc = [&](int u, int fa) {
        for (auto v: g[u]) {
            if (v == fa) continue;
            f[v] = f[u];
            f[v] -= get_sum(dfn[v], dfn[v] + siz[v] - 1);
            f[v] += sum[n - 1] - get_sum(dfn[v], dfn[v] + siz[v] - 1);
            calc(v, u);
        }
    };
    calc(0, -1);
    LL res = f[0];
    for (int i = 1; i < n; i++) {
        res = min(res, f[i]);
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