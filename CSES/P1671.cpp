#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

struct edge {
    int to, cost;
    edge(int to, int cost) {
        this->to = to;
        this->cost = cost;
    }
};
vector<vector<edge>> adj;
vector<LL> dijkstra(int st) {
    // construct graph: adj[u].emplace_back(v, c)
    const LL inf = 1ll << 60;
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
    adj.resize(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        adj[u].emplace_back(v, w);
    }
    vector<LL> dist = dijkstra(0);
    for (int i = 0; i < n; i++) {
        cout << dist[i] << ' ';
    }
    cout << endl;
}

int main() {
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}