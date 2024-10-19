#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

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
    vector<int> d(n, -1);
    queue<int> q;
    d[0] = 0;
    q.push(0);
    int res = 1e9;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        // cout << u << ' ' << d[u] << endl;
        for (auto v: g[u]) {
            if (d[v] == -1) {
                q.push(v);
                d[v] = d[u] + 1;
            } else if (v == 0) {
                res = min(res, d[u]);
            }
        }
    }
    if (res == 1e9) cout << -1 << endl;
    else cout << res + 1 << endl;
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