#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for (auto& x: a) cin >> x;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    LL inf = 1ll << 60;
    vector dp(n, vector<LL>(k + 1, inf));
    priority_queue<pair<LL, pair<int, int>>, vector<pair<LL, pair<int, int>>>, greater<pair<LL, pair<int, int>>>> pq;
    dp[0][0] = a[0];
    pq.push({dp[0][0], {0, 0}});
    if (k >= 1) {
        dp[0][1] = 1;
        pq.push({dp[0][1], {0, 1}});
    }
    while (!pq.empty()) {
        auto [val, key] = pq.top(); pq.pop();
        int u = key.first, j = key.second;
        if (val > dp[u][j]) continue;
        for (auto v: g[u]) {
            if (dp[u][j] + a[v] < dp[v][0]) {
                dp[v][0] = dp[u][j] + a[v];
                pq.push({dp[v][0], {v, 0}});
            }
            if (j + 1 <= k && dp[u][j] + 1 < dp[v][j + 1]) {
                dp[v][j + 1] = dp[u][j] + 1;
                pq.push({dp[v][j + 1], {v, j + 1}});
            }
        }
    }
    LL res = inf;
    for (int j = 0; j <= k; j++) {
        res = min(res, dp[n - 1][j]);
    }
    cout << res << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int ts = 1;
    cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}