#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

struct union_find{
    int N;
    vector<int> par, siz, edg;
    union_find(int n) : N(n){
        par.resize(N);
        siz.resize(N, 1);
        edg.resize(N);
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
        if(X == Y) {
            edg[X]++;
            return;
        }
        if(siz[Y] < siz[X]) std::swap(X, Y);
        par[X] = Y;
        siz[Y] += siz[X];
        siz[X] = 0;
        edg[Y] += edg[X];
        edg[Y]++;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    union_find dsu(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        dsu.unite(u, v);
    }
    for (int i = 0; i < n; i++) {
        int r = dsu.root(i);
        if (dsu.siz[r] != dsu.edg[r]) {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
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