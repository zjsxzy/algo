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
    vector<vector<pair<int, int>>> g(n);
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }
    vector<int> p(n), dist(n, -1);
    function<void(int, int, int)> dfs = [&](int u, int fa, int len) {
        p[u] = fa;
        dist[u] = len;
        // cout << u + 1 << ' ' << len << endl;
        for (auto e: g[u]) {
            int v = e.first, w = e.second;
            if (fa != v && dist[v] == -1) {
                dfs(v, u, len + w);
            }
        }
    };
    vector<int> nodes;
    for (int i = 0; i < m; i++) {
        int c;
        cin >> c;
        c--;
        nodes.push_back(c);
    }
    int root = nodes[0];
    dfs(root, -1, 0);
    vector<pair<int, int>> vec;
    for (int i = 0; i < m; i++) {
        vec.emplace_back(dist[nodes[i]], nodes[i]);
    }
    sort(vec.rbegin(), vec.rend());
    vector<vector<pair<int, int>>> g2(n);
    union_find dsu(n);
    int sum = 0;
    for (int i = 1; i < m; i++) {
        int x = nodes[i];
        while (!dsu.same(root, x)) {
            g2[x].emplace_back(p[x], dist[x] - dist[p[x]]);
            g2[p[x]].emplace_back(x, dist[x] - dist[p[x]]);
            // cout << x + 1 << ' ' << p[x] + 1 << ' ' << dist[x] - dist[p[x]] << endl;
            sum += dist[x] - dist[p[x]];
            dsu.unite(x, p[x]);
            x = p[x];
        }
    }
    // cout << sum << endl;
    auto bfs = [&](int p) {
        queue<int> q;
        q.push(p);
        vector<int> d(n, -1);
        d[p] = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (auto e: g2[u]) {
                int v = e.first, w = e.second;
                if (d[v] == -1) {
                    d[v] = d[u] + w;
                    q.push(v);
                }
            }
        }
        pair<int, int> res = {0, -1};
        for (int i = 0; i < n; i++) {
            if (d[i] > res.first) {
                res = {d[i], i};
            }
        }
        return res;
    };
    pair<int, int> ans = bfs(root);
    pair<int, int> ans2 = bfs(ans.second);
    cout << sum * 2 - ans.first << endl;
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