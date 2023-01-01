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
    int n, m;
    cin >> n >> m;
    vector<pair<int, pair<int, int>>> edges;
    union_find dsu(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        edges.push_back({w, {u, v}});
    }
    sort(edges.begin(), edges.end());
    LL res = 0;
    for (int i = 0; i < m; i++) {
        int u = edges[i].second.first, v = edges[i].second.second, w = edges[i].first;
        if (dsu.same(u, v)) continue;
        res += w; 
        dsu.unite(u, v);
    }
    int cnt = 0;
    for (int i = 1; i < n; i++) {
        if (dsu.root(i) == i) {
            cnt++;
            if (cnt > 1) {
                cout << "IMPOSSIBLE" << endl;
                return;
            }
        }
    }
    cout << res << endl;
}

int main() {
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}