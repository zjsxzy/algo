#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    vector deg(n, 0), dp(n, 0);
    const int mod = 1e9 + 7;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        deg[v]++;
    }
    dp[0] = 1;
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (deg[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto v: g[u]) {
            dp[v] += dp[u];
            dp[v] %= mod;
            deg[v]--;
            if (deg[v] == 0) {
                q.push(v);
            }
        }
    }
    cout << dp[n - 1] << endl;
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