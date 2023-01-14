#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int mod = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
    }
    vector<vector<int>> dp(n, vector<int>(1 << n));
    dp[0][1] = 1;
    for (int s = 1; s < (1 << n); s++) {
        for (int u = 0; u < n; u++) {
            if (!dp[u][s]) continue;
            for (auto v: g[u]) {
                if (s >> v & 1) continue;
                dp[v][s | (1 << v)] += dp[u][s];
                dp[v][s | (1 << v)] %= mod;
            }
        }
    }
    cout << dp[n - 1][(1 << n) - 1] << endl;
}

int main() {
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}