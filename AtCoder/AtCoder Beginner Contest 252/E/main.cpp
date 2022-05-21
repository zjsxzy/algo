#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const LL INF = 1ll << 60;
vector<int> ans;
struct Edge {
    LL w = INF;
    int to = -1, idx;
    Edge() {}
    Edge(LL w_, int to_, int idx_) : to(to_), w(w_), idx(idx_) {}
    bool operator<(Edge const& other) const {
        return make_pair(w, to) < make_pair(other.w, other.to);
    }
};
void prims(vector<vector<Edge>> &adj,int &n) {
    vector<Edge> min_e(n);
    min_e[0].w = 0;
    set<Edge> q;
    q.insert({0, 0, 0});
    vector<bool> selected(n, false);
    for (int i = 0; i < n; ++i) {

        int v = q.begin()->to;
        selected[v] = true;
        if (q.begin()->idx > 0) ans.push_back(q.begin()->idx);
        q.erase(q.begin());

        for (Edge e : adj[v]) {
            if (!selected[e.to] && min_e[v].w + e.w < min_e[e.to].w) {
                q.erase({min_e[e.to].w, e.to, min_e[e.to].idx});
                min_e[e.to] = {min_e[v].w + e.w, v, e.idx};
                q.insert({min_e[v].w + e.w, e.to, e.idx});
            }
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<Edge>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        LL w;
        cin >> u >> v >> w;
        u--; v--;
        adj[u].emplace_back(w, v, i + 1);
        adj[v].emplace_back(w, u, i + 1);
    }
    prims(adj, n);
    for (auto x: ans) cout << x << ' ';
    cout << endl;
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


