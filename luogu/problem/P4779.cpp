#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int inf = (1LL << 31) - 1;
struct edge {
    int to, cost;
    edge(int to, int cost) {
        this->to = to;
        this->cost = cost;
    }
};
vector<vector<edge>> adj;
vector<int> dist;

void dijkstra(int st) {
    for (int i = 0; i < adj.size(); i++) {
        dist[i] = inf;
    }
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
}

void solve() {
    int n, m, s;
    cin >> n >> m >> s;
    s--;
    adj.resize(n);
    dist.resize(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        adj[u].push_back({v, w});
    }
    dijkstra(s);
    for (int i = 0; i < n; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;
}

int main() {
    solve();
    return 0;
}

