#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, m, q, x;
    cin >> n >> m >> q >> x;
    x--;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    queue<int> Q;
    Q.push(x);
    vector<int> dist(n, -1);
    dist[x] = 0;
    int maxd = 0;
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        maxd = max(maxd, dist[u]);
        for (auto v: g[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                Q.push(v);
            }
        }
    }
    vector<LL> cnt(maxd + 1);
    for (int i = 0; i < n; i++) {
        if (dist[i] > 0) cnt[dist[i]]++;
    }
    vector<vector<LL>> dp(maxd + 1, vector<LL>(maxd + 1, 0));
    dp[0][0] = 1;
    const int MOD = 1e9 + 7;
    for (int i = 1; i <= maxd; i++) {
        dp[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            dp[i][j] += dp[i - 1][j];
            dp[i][j] %= MOD;
            dp[i][j] += dp[i - 1][j - 1] * cnt[i];
            dp[i][j] %= MOD;
        }
    }
    while (q--) {
        int k;
        cin >> k;
        if (k > maxd) cout << 0 << endl;
        else cout << dp[maxd][k] << endl;
    }
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