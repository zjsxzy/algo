/*
ID: frankzh1
TASK: comehome
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int inf = 1e9;
struct edge {
    int to, cost;
    edge(int to, int cost) {
        this->to = to;
        this->cost = cost;
    }
};

void solve() {
    int m, n = 0;
    cin >> m;
    vector<vector<edge> > adj(105);
    map<char, int> idx;
    for (int i = 0; i < m; i++) {
        char u, v;
        int w;
        cin >> u >> v >> w;
        if (idx.find(u) == idx.end()) {
            idx[u] = n++;
        }
        if (idx.find(v) == idx.end()) {
            idx[v] = n++;
        }
        if (u != v) {
            adj[idx[u]].emplace_back(idx[v], w);
            adj[idx[v]].emplace_back(idx[u], w);
        }
    }

    vector<int> dist(n, inf);
    int st = idx['Z'];
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
    int res = INT_MAX;
    char p;
    for (auto &[k, v]: idx) {
        if (k >= 'A' && k < 'Z' && dist[v] < res) {
            p = k;
            res = dist[v];
        }
    }
    cout << p << " " << res << endl;
}

int main() {
    freopen("comehome.in", "r", stdin);
    freopen("comehome.out", "w", stdout);
    solve();
    return 0;
}

