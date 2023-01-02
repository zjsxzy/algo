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
    union_find dsu(n);
    int cnt = n, sz = 1;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        if (dsu.same(a, b)) {
            cout << cnt << ' ' << sz << endl;
        } else {
            cnt--;
            dsu.unite(a, b);
            if (dsu.siz[dsu.root(a)] > sz) sz = dsu.siz[dsu.root(a)];
            cout << cnt << ' ' << sz << endl;
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