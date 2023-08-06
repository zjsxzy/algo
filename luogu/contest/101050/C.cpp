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
const int inf = 1e9;
vector<vector<edge>> adj;
int dijkstra(int st, int ed) {
    // vector<vector<edge> > adj(n);
    // construct graph: adj[u].emplace_back(v, c)
    vector<pair<int, int>> dist(adj.size(), {inf, inf});
    dist[st] = {0, 1};
    priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, greater<pair<pair<int, int>, int>>> pq;
    pq.push({{0, 1}, st});
    while (!pq.empty()) {
        auto [p, v] = pq.top(); pq.pop();
        for (edge e : adj[v]) {
            pair<int, int> nd = {p.first + e.cost / p.second, p.second + 1};
            if (nd < dist[e.to]) {
                dist[e.to] = nd;
                pq.push({nd, e.to});
            }
        }
    }
    return dist[ed].first;
}

void solve() {
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    s--; t--;
    adj.assign(n, {});
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    int res = dijkstra(t, s);
    std::cout << res << endl;
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