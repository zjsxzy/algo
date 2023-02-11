#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> color(n);
    for (int i = 0; i < n; i++) cin >> color[i];
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if (color[0] == color[n - 1]) {
        cout << -1 << endl;
        return;
    }
    queue<pair<int, int>> q;
    q.push({0, n - 1});
    vector<vector<int>> dp(n, vector<int>(n, 1e9));
    dp[0][n - 1] = 0;
    while (!q.empty()) {
        auto curr = q.front(); q.pop();
        int u = curr.first, v = curr.second;
        for (auto a: g[u]) {
            for (auto b: g[v]) {
                if (color[a] != color[b] && dp[u][v] + 1 < dp[a][b]) {
                    dp[a][b] = dp[u][v] + 1;
                    q.push({a, b});
                }
            }
        }
    }
    int res = dp[n - 1][0];
    if (res == 1e9) res = -1;
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