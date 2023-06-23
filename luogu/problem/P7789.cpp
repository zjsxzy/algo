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
    cin >> n;
    vector<int> p(n);
    for (auto& x: p) cin >> x;
    sort(p.begin(), p.end());
    p.resize(unique(p.begin(), p.end()) - p.begin());
    int mx = p[p.size() - 1];
    // vector<pair<int, pair<int, int>>> edges;
    // for (int i = 0; i < (int)p.size(); i++) {
    //     int x = p[i];
    //     for (int l = x; l <= mx; l += x) {
    //         auto it = lower_bound(p.begin() + i + 1, p.end(), l) - p.begin();
    //         if (it < (int)p.size() && p[it] < l + x) {
    //             edges.push_back({p[it] % x, {i, it}});
    //         }
    //     }
    // }
    vector<int> bucket(mx + 1), idx(mx + 1, -1);
    for (int i = 0; i < (int)p.size(); i++) {
        bucket[p[i]] = p[i];
        idx[p[i]] = i;
    }
    for (int i = mx; i >= 0; i--) {
        if (!bucket[i]) bucket[i] = bucket[i + 1];
    }
    vector<vector<pair<int, int>>> edges(mx + 1);
    for (int i = 0; i < (int)p.size(); i++) {
        int x = p[i];
        if (x + 1 <= mx) {
            int it = idx[bucket[x + 1]];
            if (p[it] < 2 * x) {
                // edges.push_back({p[it] % x, {i, it}});
                edges[p[it] % x].push_back({i, it});
            }
        }
        for (int l = 2 * x; l <= mx; l += x) {
            int it = idx[bucket[l]];
            if (p[it] < l + x) {
                // edges.push_back({p[it] % x, {i, it}});
                edges[p[it] % x].push_back({i, it});
            }
        }
    }

    // sort(edges.begin(), edges.end());
    union_find dsu((int)p.size());
    LL res = 0;
    // for (int i = 0; i < (int)edges.size(); i++) {
    //     int u = edges[i].second.first, v = edges[i].second.second, w = edges[i].first;
    //     if (dsu.same(u, v)) continue;
    //     res += w;
    //     dsu.unite(u, v);
    // }
    for (int w = 0; w <= mx; w++) {
        if (edges[w].size() == 0) continue;
        for (int i = 0; i < edges[w].size(); i++) {
            int u = edges[w][i].first, v = edges[w][i].second;
            if (dsu.same(u, v)) continue;
            res += w;
            dsu.unite(u, v);
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