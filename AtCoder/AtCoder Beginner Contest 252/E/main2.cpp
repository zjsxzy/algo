#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const LL INF = 1ll << 60;
map<pair<int, int>, int> mp;
struct edge {
    int to;
    LL cost;
    edge(int to, LL cost) {
        this->to = to;
        this->cost = cost;
    }
};
vector<vector<edge>> adj;
void dijkstra(int st) {
    // construct graph: adj[u].emplace_back(v, c)
    vector<LL> dist(adj.size(), INF);
    vector<int> prev(adj.size(), -1);
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
                prev[e.to] = v;
                pq.push({nd, e.to});
            }
        }
    }
    set<int> ans;
    int n = adj.size();
    for (int i = 0; i < n; i++) {
        if (prev[i] != -1) {
            ans.insert(mp[{i, prev[i]}]);
        }
    }
    for (auto x: ans) cout << x << ' ';
    cout << endl;
}

void solve() {
    int n, m;
    cin >> n >> m;
    adj.resize(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        LL w;
        cin >> u >> v >> w;
        u--; v--;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
        mp[{u, v}] = mp[{v, u}] = i + 1;
    }
    dijkstra(0);
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("in.txt", "r", stdin);
#endif
   int ts = 1;
   // cin >> ts;
   for (int t = 1; t <= ts; t++) {
       solve();
   }
   return 0;
}


