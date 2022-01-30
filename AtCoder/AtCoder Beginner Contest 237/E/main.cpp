#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const LL inf = 1LL << 60;
const int maxn = 200005;
struct edge {
    int to;
    LL cost;
    edge(int to, LL cost) {
        this->to = to;
        this->cost = cost;
    }
};
int n, m;
int h[maxn];
LL dist[maxn], ans[maxn];
vector<edge> adj[maxn];

void addEdge(int u, int v, LL w) {
    // cout << u << " " << v << " " << w << endl;
    adj[u].push_back({v, w});
}

void dijkstra(int st) {
    for (int i = 1; i <= n; i++) dist[i] = inf;
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
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> h[i];
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        if (h[v] > h[u]) {
            addEdge(u, v, 2 * (h[v] - h[u]));
            addEdge(v, u, h[u] - h[v]);
        } else {
            addEdge(u, v, h[v] - h[u]);
            addEdge(v, u, 2 * (h[u] - h[v]));
        }
    }
    dijkstra(1);
    LL res = 0;
    for (int i = 1; i <= n; i++) {
        // cout << i << " " << dist[i] << endl;
        res = min(res, dist[i]);
    }
    cout << -res << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

