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
    int n;
    while (cin >> n) {
        vector<pair<int, pair<int, int>>> edges;
        for (int i = 1; i < n; i++) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            u--; v--;
            edges.push_back({-w, {u, v}});
        }
        sort(edges.begin(), edges.end());
        union_find dsu(n);
        vector<LL> val(n);
        for (int i = 0; i < n - 1; i++) {
            LL w = -edges[i].first;
            int u = edges[i].second.first, v = edges[i].second.second;
            LL v1 = val[dsu.root(u)] + w * dsu.siz[dsu.root(v)];
            LL v2 = val[dsu.root(v)] + w * dsu.siz[dsu.root(u)];
            dsu.unite(u, v);
            val[dsu.root(u)] = max(v1, v2);
        }
        cout << val[dsu.root(0)] << endl;
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