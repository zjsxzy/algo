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
    vector<pair<LL, pair<int, int>>> eds;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> y[i];
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        LL w;
        cin >> u >> v >> w;
        u--; v--;
        eds.push_back({w, {u, v}});
    }
    LL res = 1ll << 60;
    for (int a = 0; a < 2; a++) {
        for (int b = 0; b < 2; b++) {
            union_find uf(n + 2);
            vector<pair<LL, pair<int, int>>> edges = eds;
            if (a) {
                for (int i = 0; i < n; i++) {
                    edges.push_back({x[i], {i, n}});
                }
            }
            if (b) {
                for (int i = 0; i < n; i++) {
                    edges.push_back({y[i], {i, n + 1}});
                }
            }
            sort(edges.begin(), edges.end());
            LL sum = 0;
            for (int i = 0; i < (int)edges.size(); i++) {
                LL w = edges[i].first;
                int u = edges[i].second.first, v = edges[i].second.second;
                if (!uf.same(u, v)) {
                    sum += w;
                    uf.unite(u, v);
                }
            }
            if (uf.siz[uf.root(0)] == n + a + b) res = min(res, sum);
        }
    }
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

