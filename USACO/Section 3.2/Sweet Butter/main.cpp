/*
ID: frankzh1
TASK: butter
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int MAXN = 805;
const int inf = 1e9;
struct edge {
    int to, cost;
    edge(int to, int cost) {
        this->to = to;
        this->cost = cost;
    }
};
vector<vector<edge>> adj;
vector<int> cow;
int p, n, m;

int dijkstra(int st) {
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
    int tot = 0;
    for (int i = 0; i < p; i++) {
        if (dist[cow[i]] == inf) return inf;
        else tot += dist[cow[i]];
    }
    return tot;
}

void solve() {
    cin >> p >> n >> m;
    adj.resize(n);
    cow.resize(p);
    for (auto &x: cow) {
        cin >> x;
        x--;
    }
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    int res = inf;
    for (int i = 0; i < n; i++) {
        int sum = dijkstra(i);
        //cout << i + 1 << " " << sum << endl;
        res = min(res, sum);
    }
    cout << res << endl;
}

int main() {
    freopen("butter.in", "r", stdin);
    freopen("butter.out", "w", stdout);
    solve();
    return 0;
}

