#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
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
    vector<int> d(n);
    union_find uf(n);
    LL sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> d[i];
        sum += d[i];
    }
    if (2 * (n - 1) != sum) {
        cout << -1 << endl;
        return;
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        d[a]--; d[b]--;
        if (uf.same(a, b)) {
            cout << -1 << endl;
            return;
        }
        if (d[a] < 0 || d[b] < 0) {
            cout << -1 << endl;
            return;
        }
        uf.unite(a, b);
    }
    vector<vector<int>> a(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < d[i]; j++) {
            a[uf.root(i)].push_back(i);
        }
    }
    priority_queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        if (!a[i].empty()) q.push({a[i].size(), i});
    }
    vector<pair<int, int>> ans;
    while (q.size() > 1) {
        auto [s1, u] = q.top(); q.pop();
        auto [s2, v] = q.top(); q.pop();
        uf.unite(u, v);
        ans.push_back({a[u].back(), a[v].back()});
        a[u].pop_back(); a[v].pop_back();
        for (auto x: a[v]) a[u].push_back(x);
        if (uf.root(u) == v) swap(a[u], a[v]);
        q.push({s1 + s2 - 2, uf.root(u)});
    }
    if (ans.size() == n - m - 1) {
        for (auto [u, v]: ans) {
            cout << u + 1 << " " << v + 1 << endl;
        }
    } else {
        cout << -1 << endl;
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

