#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<pair<int, pair<int, int>>> edges;
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a > b) swap(a, b);
        edges.push_back({-c, {a, b}});
    }
    sort(edges.begin(), edges.end());

    map<pair<int, int>, LL> res;
    vector<pair<int, int>> query;
    for (int i = 0; i < Q; i++) {
        int x, y;
        cin >> x >> y;
        if (x > y) swap(x, y);
        query.emplace_back(x, y);
        res[{x, y}] = 0;
    }

    vector<vector<int>> adj(N + 1);
    for (int i = 0; i < M; i++) {
        int a = edges[i].second.first, b = edges[i].second.second, c = -edges[i].first;
        if (res.find({a, b}) != res.end()) {
            res[{a, b}] += 2ll * c;
        }
        for (auto v: adj[b]) {
            int u = a;
            if (u > v) swap(u, v);
            if (res.find({u, v}) != res.end()) {
                res[{u, v}] += c;
            }
        }
        for (auto v: adj[a]) {
            int u = b;
            if (u > v) swap(u, v);
            if (res.find({u, v}) != res.end()) {
                res[{u, v}] += c;
            }
        }
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (auto q: query) cout << " " << res[q];
    cout << endl;
}

int main() {
   int ts = 1;
   cin >> ts;
   for (int t = 1; t <= ts; t++) {
       cout << "Case #" << t << ":";
       solve();
   }
   return 0;
}

