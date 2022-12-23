#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

struct union_find{
    int N;
    vector<int> par, siz;
    union_find(int n) : N(n){
        par.resize(N);
        siz.resize(N, 1);
        for(int i=0; i<N; i++) par[i] = i;
    }
    int root(int X){
        if(par[X] == X) return X;
        return par[X] = root(par[X]);
    }
    bool same(int X, int Y){
        return root(X) == root(Y);
    }
    void unite(int X, int Y){
        X = root(X);
        Y = root(Y);
        if(X == Y) return;
        if(siz[Y] < siz[X]) std::swap(X, Y);
        par[X] = Y;
        siz[Y] += siz[X];
        siz[X] = 0;
    }
};

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<pair<int, LL>>> g(n);
    union_find dsu(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        dsu.unite(u, v);
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, -w);
    }
    vector<int> vis(n), cycle(n);
    vector<LL> d(n);
    function<void(int)> dfs = [&](int u) {
        vis[u] = true;
        for (auto [v, w]: g[u]) {
            if (!vis[v]) {
                d[v] = d[u] + w;
                dfs(v);
            } else if (d[v] != d[u] + w) {
                cycle[dsu.root(v)] = true;
            }
        }
    };
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(i);
        }
    }
    while (q--) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        if (!dsu.same(x, y)) {
            cout << "nan" << endl;
        } else if (cycle[dsu.root(x)]) {
            cout << "inf" << endl;
        } else {
            cout << d[y] - d[x] << endl;
        }
    }
}

int main() {
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}