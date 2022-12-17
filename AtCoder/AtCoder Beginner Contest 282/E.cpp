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

LL quickpow(LL x, LL n, LL mod) {
    LL res = 1;
    for (; n; n >>= 1) {
        if (n & 1) res = res * x % mod;
        x = x * x % mod;
    }
    return res;
}

void solve() {
    int n;
    LL M;
    cin >> n >> M;
    vector<LL> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<pair<LL, pair<int, int>>> edgs;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            LL w = (quickpow(a[i], a[j], M) + quickpow(a[j], a[i], M)) % M;
            edgs.push_back({-w, {i, j}});
        }
    }
    sort(edgs.begin(), edgs.end());
    LL res = 0;
    union_find dsu(n);
    for (int i = 0; i < (int)edgs.size(); i++) {
        auto w = -edgs[i].first;
        auto [u, v] = edgs[i].second;
        if (dsu.root(u) == dsu.root(v)) continue;
        res += w;
        dsu.unite(u, v);
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
