#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int maxn = 200005;
int n;
vector<int> adj[maxn];
int tot;
int l[maxn], r[maxn];

void dfs(int u, int p) {
    bool leaf = true;
    for (auto v: adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        leaf = false;
        l[u] = min(l[u], l[v]);
        r[u] = max(r[u], r[v]);
    }
    if (leaf) {
        l[u] = tot;
        r[u] = tot;
        tot++;
    }
}

void solve() {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        l[i] = n + 1;
        r[i] = 0;
    }
    tot = 1;
    dfs(1, 0);
    for (int i = 1; i <= n; i++) {
        cout << l[i] << " " << r[i] << endl;
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

