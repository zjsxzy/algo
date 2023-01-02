#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const LL inf = 1ll << 60;
struct edge {
    int to, cost;
    edge(int to, int cost) {
        this->to = to;
        this->cost = cost;
    }
};

vector<LL> dijkstra(int st, vector<vector<edge>>& adj) {
    // vector<vector<edge> > adj(n);
    // construct graph: adj[u].emplace_back(v, c)
    vector<LL> dist(adj.size(), inf);
    dist[st] = 0;
    priority_queue<pair<LL, int>, vector<pair<LL, int>>, greater<pair<LL, int>>> pq;
    pq.push({0, st});
    while (!pq.empty()) {
        auto p = pq.top(); pq.pop();
        int v = p.second;
        if (p.first > dist[v]) continue;
        for (edge e : adj[v]) {
            LL nd = p.first + e.cost;
            if (nd < dist[e.to]) {
                dist[e.to] = nd;
                pq.push({nd, e.to});
            }
        }
    }
    return dist;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<edge>> g(n), rg(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        g[u].emplace_back(v, w);
        rg[v].emplace_back(u, w);
    }
    vector<LL> d = dijkstra(0, g);
    vector<LL> rd = dijkstra(n - 1, rg);
    LL res = inf;
    for (int u = 0; u < n; u++) {
        for (auto [v, w]: g[u]) {
            res = min(res, d[u] + w / 2 + rd[v]);
        }
    }
    cout << res << endl;
}

int main() {
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}