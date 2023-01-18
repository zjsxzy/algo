#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int inf = 1e9;
struct edge {
    int to, cost;
    edge(int to, int cost) {
        this->to = to;
        this->cost = cost;
    }
};
vector<vector<edge>> adj;

vector<int> dijkstra(int st) {
    // vector<vector<edge> > adj(n);
    // construct graph: adj[u].emplace_back(v, c)
    vector<int> dist(adj.size(), inf);
    dist[st] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, st});
    while (!pq.empty()) {
        auto p = pq.top(); pq.pop();
        int v = p.second;
        if (p.first > dist[v]) continue;
        for (edge e : adj[v]) {
            int nd = p.first + e.cost;
            if (nd < dist[e.to]) {
                dist[e.to] = nd;
                pq.push({nd, e.to});
            }
        }
    }
    return dist;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    adj.resize(2 * n);
    for (int i = 0; i < m; i++) {
        int u, v, a;
        cin >> u >> v >> a;
        u--; v--;
        if (a) {
            adj[u].emplace_back(v, 1);
            adj[v].emplace_back(u, 1);
        } else {
            adj[u + n].emplace_back(v + n, 1);
            adj[v + n].emplace_back(u + n, 1);
        }
    }
    for (int i = 0; i < k; i++) {
        int u;
        cin >> u;
        u--;
        adj[u].emplace_back(u + n, 0);
        adj[u + n].emplace_back(u, 0);
    }
    vector<int> d = dijkstra(0);
    int res = min(d[n - 1], d[n + n - 1]);
    if (res == inf) res = -1;
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