struct edge {
    int to, cost;
    edge(int to, int cost) {
        this->to = to;
        this->cost = cost;
    }
};
int dijkstra(int st, int ed) {
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
    return dist[ed];
}

