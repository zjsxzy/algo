#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

struct union_find{
    int N;
    vector<int> par, siz;
    vector<LL> weight;
    union_find(int n) : N(n){
        par.resize(N);
        siz.resize(N, 1);
        weight.resize(N, 0LL);
        for(int i=0; i<N; i++) par[i] = i;
    }
    int root(int X){
        if(par[X] == X) return X;
        return par[X] = root(par[X]);
    }
    bool same(int X, int Y){
        return root(X) == root(Y);
    }
    void unite(int X, int Y, int Z){
        X = root(X);
        Y = root(Y);
        if(X == Y) return;
        if(siz[Y] < siz[X]) std::swap(X, Y);
        par[X] = Y;
        siz[Y] += siz[X];
        siz[X] = 0;
        weight[Y] += weight[X];
        weight[Y] += Z;
        weight[X] = 0;
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    union_find dsu(n);
    vector<pair<int, pair<int, int>>> edges;
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        edges.push_back({w, {u, v}});
    }
    vector<pair<int, int>> queries;
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        queries.push_back({x, y});
    }
    const LL inf = 1LL << 60;
    vector<LL> ans(q, -inf);
    sort(edges.rbegin(), edges.rend());
    for (auto e: edges) {
        int w = e.first, u = e.second.first, v = e.second.second;
        dsu.unite(u, v, w);
        for (int i = 0; i < q; i++) {
            if (dsu.same(queries[i].first, queries[i].second) && dsu.weight[dsu.root(queries[i].first)] > ans[i]) {
                ans[i] = dsu.weight[dsu.root(queries[i].first)];
            }
        }
    }
    for (int i = 0; i < q; i++) cout << ans[i] << endl;
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