#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x: a) cin >> x;
    vector e(n, vector(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> e[i][j];
        }
    }
    LL res = 1e18;
    for (int st = 0; st < n; st++) {
        vector dp(n, vector(1 << n, 1e9));
        dp[st][0] = 0;
        for (int s = 1; s < (1 << n); s++) {
            for (int u = 0; u < n; u++) {
                if (s >> u & 1) {
                    LL nodes = f[u][s], edges = g[u][s];
                    for (int v = 0; v < n; v++) {
                        if (e[u][v] && !(s >> v & 1) && (nodes + a[v]) * (edges + e[u][v]) < (LL)f[v][s | (1 << v)] * g[v][s | (1 << v)]) {
                            f[v][s | (1 << v)] = nodes + a[v];
                            g[v][s | (1 << v)] = edges + e[u][v]; 
                        }
                    }
                }
            }
        }
        for (int s = 1; s < (1 << n); s++) {
            for (int u = 0; u < n; u++) {
                if (u != st && e[u][st] && __builtin_popcount(s) > 2) {
                    LL nodes = f[u][s], edges = g[u][s];
                    res = min(res, (nodes + a[st]) * (edges + e[u][st]));
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (dsu.same(st, i)) vst[i] = 1;
        }
    }
    if (res == 1e18) res = -1;
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