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
    vector<vector<int>> edges;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        edges.push_back({u, v, w});
    }
    int q;
    cin >> q;
    vector<vector<int>> queries(q);
    for (int i = 0; i < q; i++) {
        int s;
        cin >> s;
        for (int j = 0; j < s; j++) {
            int u;
            cin >> u;
            u--;
            queries[i].push_back(u);
        }
    }
    sort(edges.begin(), edges.end(), [](auto a, auto b){
        return a[2] < b[2];
    });
    auto check = [&](int x) {
        union_find dsu(n);
        for (int i = 0; i < m; i++) {
            if (edges[i][2] > x) break;
            int u = edges[i][0], v = edges[i][1];
            dsu.unite(u, v);
        }
        for (int i = 0; i < q; i++) {
            for (int j = 1; j < queries[i].size(); j++) {
                if (!dsu.same(queries[i][0], queries[i][j])) return false;
            } 
        }
        return true;
    };
    int lo = 0, hi = 1e9, res;
    while (lo <= hi) {
        int mid = (lo + hi) >> 1;
        if (check(mid)) {
            res = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    cout << res << endl;
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