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
    vector<LL> x(n), y(n);
    vector<pair<LL, pair<int, int>>> edges;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        edges.push_back({x[i], {i, n}});
    }
    for (int i = 0; i < n; i++) {
        cin >> y[i];
        edges.push_back({y[i], {i, n + 1}});
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        LL w;
        cin >> u >> v >> w;
        u--; v--;
        edges.push_back({w, {u, v}});
    }
    union_find uf(n + 2);
    sort(edges.begin(), edges.end());
    LL res = 0;
    vector<LL> node1, node2;
    for (int i = 0; i < (int)edges.size(); i++) {
        LL w = edges[i].first;
        int u = edges[i].second.first, v = edges[i].second.second;
        if (!uf.same(u, v)) {
            res += w;
            if (v == n) node1.push_back(w);
            if (v == n + 1) node2.push_back(w);
            uf.unite(u, v);
        }
    }
    if ((int)node1.size() == 1) res -= node1[0];
    if ((int)node2.size() == 1) res -= node2[0];
    cout << res << endl;
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


