#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

struct union_find{
    int N;
    vector<int> par, siz, cntA, cntB;
    union_find(int n) : N(n){
        par.resize(N);
        siz.resize(N, 1);
        cntA.resize(N);
        cntB.resize(N);
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
        cntA[Y] += cntA[X];
        cntB[Y] += cntB[X];
        siz[X] = 0;
    }
};

void solve() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<pair<int, pair<int, int>>> edges(M);
    for (int i = 0; i < M; i++) {
        cin >> edges[i].second.first >> edges[i].second.second >> edges[i].first;
        edges[i].second.first--;
        edges[i].second.second--;
    }
    union_find dsu(N);
    for (int i = 0; i < K; i++) {
        int x;
        cin >> x;
        x--;
        dsu.cntA[x]++;
    }
    for (int i = 0; i < K; i++) {
        int x;
        cin >> x;
        x--;
        dsu.cntB[x]++;
    }
    sort(edges.begin(), edges.end());
    LL res = 0;
    for (auto e: edges) {
        int u = e.second.first, v = e.second.second, w = e.first;
        if (dsu.same(u, v)) continue;
        dsu.unite(u, v);
        int t = min(dsu.cntA[dsu.root(u)], dsu.cntB[dsu.root(u)]);
        res += (LL)w * t;
        dsu.cntA[dsu.root(u)] -= t;
        dsu.cntB[dsu.root(u)] -= t;
    }
    cout << res << '\n';
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