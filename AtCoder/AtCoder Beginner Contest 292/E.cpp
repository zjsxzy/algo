#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n, vector<int>(n));
    vector<vector<int>> adj(n);
    vector<pair<int, int>> edges;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u][v] = 1;
        adj[u].push_back(v);
        edges.emplace_back(u, v);
    }
    int res = 0;
    vector<int> vst(n);
    for (int i = 0; i < m; i++) {
        queue<int> q;
        q.push(edges[i].second);
        vst.assign(n, 0);
        vst[edges[i].second] = 1;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            vst[u] = 1;
            for (auto v: adj[u]) {
                if (!vst[v]) {
                    q.push(v);
                }
            }
        }
        for (int u = 0; u < n; u++) {
            if (u == edges[i].first || u == edges[i].second || !vst[u]) continue;
            if (g[edges[i].first][u] == 0) {
                g[edges[i].first][u] = 1;
                res++;
            }
        }
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