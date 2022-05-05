#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 200005;
vector<int> adj[maxn];
int sz[maxn], fa[maxn], a[maxn], nd[maxn];
map<pair<int, int>, bool> ed;
int res = 0;

void dfs(int u, int p) {
    sz[u] = nd[u];
    fa[u] = p;
    for (auto v: adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        sz[u] += sz[v];
    }
}

void dfs2(int u, int p) {
    for (auto v: adj[u]) {
        if (!sz[v] || v == p) continue;
        if (ed[{u, v}]) res++;
        else res += 2;
        dfs2(v, u);
    }
}

void solve() {
    int n, k, x, y;
    cin >> n >> k >> x >> y;
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
    }
    ed.clear();
    memset(nd, 0, sizeof(nd));
    memset(sz, 0, sizeof(sz));
    memset(fa, 0, sizeof(fa));
    nd[x] = 1; nd[y] = 1;
    for (int i = 0; i < k; i++) {
        cin >> a[i];
        nd[a[i]] = 1;
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(x, 0);
    int t = y;
    while (t != x) {
        ed[{t, fa[t]}] = ed[{fa[t], t}] = 1;
        t = fa[t];
    }
    res = 0;
    dfs2(x, 0);
    cout << res << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int ts;
    cin >> ts;
    while (ts--) {
        solve();
    }
    return 0;
}

