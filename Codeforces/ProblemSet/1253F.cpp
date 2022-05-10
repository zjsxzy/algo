#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const LL inf = 1ll << 60;
struct edge {
    int from, to;
    LL cost;
    edge(int from, int to, LL cost) {
        this->from = from;
        this->to = to;
        this->cost = cost;
    }
};
vector<vector<edge>> adj;
vector<LL> dist;
void dijkstra(int k) {
    // vector<vector<edge> > adj(n);
    // construct graph: adj[u].emplace_back(v, c)
    int n = adj.size();
    dist.assign(n, inf);
    priority_queue<pair<LL, int>, vector<pair<LL, int>>, greater<pair<LL, int>>> pq;
    for (int st = 0; st < k; st++) {
        dist[st] = 0;
        pq.push({0, st});
    }
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
vector<vector<pair<int, int>>> queries;
vector<LL> ans;
struct union_find {
    int n;
    vector<set<int>> groups;
    vector<int> owner;
    union_find(int n_) : n(n_){
        groups.assign(n, {});
        owner.resize(n);
        for (int i = 0; i < n; i++) {
            owner[i] = i;
            groups[i] = {i};
        }
    }
    void unite(int a, int b, LL w) {
        a = owner[a];
        b = owner[b];
        if (a == b) return;
        if (groups[a].size() > groups[b].size()) swap(a, b);
        for (auto x: groups[a]) {
            for (auto q: queries[x]) {
                if (groups[b].find(q.first) != groups[b].end()) {
                    ans[q.second] = w;
                }
            }
        }
        for (int x : groups[a]) {
            owner[x] = b;
            groups[b].insert(x);
        }
        groups[a].clear();
    }
};

void solve() {
    int n, m, k, q;
    cin >> n >> m >> k >> q;
    adj.assign(n, {});
    vector<edge> eds;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        adj[u].emplace_back(u, v, w);
        adj[v].emplace_back(v, u, w);
        eds.emplace_back(u, v, w);
    }
    dijkstra(k);
    for (int i = 0; i < m; i++) {
        eds[i].cost += dist[eds[i].from] + dist[eds[i].to];
    }
    queries.assign(n, {});
    ans.assign(q, -1);
    for (int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        queries[u].emplace_back(v, i);
        queries[v].emplace_back(u, i);
    }
    union_find uf(n);
    sort(eds.begin(), eds.end(), [&](const edge& a, const edge& b) {
        return a.cost < b.cost;
    });
    for (auto& e: eds) {
        uf.unite(e.from, e.to, e.cost);
    }
    for (auto& x: ans) {
        cout << x << '\n';
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

