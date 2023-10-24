#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> g(n);
    LL res = 0;
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
        res += w * 2;
    }
    function<pair<LL, int>(int)> bfs = [&](int s) {
        vector<LL> dist(n, -1);
        queue<int> q;
        dist[s] = 0;
        q.push(s);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (auto [v, w]: g[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + w;
                    q.push(v);
                }
            }
        }
        int i = max_element(dist.begin(), dist.end()) - dist.begin();
        return make_pair(dist[i], i);
    };
    auto [d, u] = bfs(0);
    auto [ans, v] = bfs(u);
    cout << res - ans << endl;
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