#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 200005;
vector<int> adj[maxn], path[maxn];
int son[maxn];
int res;

void dfs(int u, int fa) {
    bool leaf = true;
    for (auto v: adj[u]) {
        if (v == fa) continue;
        dfs(v, u);
        leaf = false;
        son[u] = son[v];
    }
    if (leaf) {
        res++;
        son[u] = u;
        path[u].push_back(u);
    } else {
        path[son[u]].push_back(u);
    }
}

void solve() {
    int n;
    cin >> n;
    int root;
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        path[i].clear();
        son[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        int p;
        cin >> p;
        if (p != i) {
            adj[i].push_back(p);
            adj[p].push_back(i);
        } else {
            root = i;
        }
    }
    res = 0;
    dfs(root, 0);
    cout << res << endl;
    for (int i = 1; i <= n; i++) {
        if (son[i] == i) {
            cout << path[i].size() << endl;
            int sz = path[i].size();
            for (int j = sz - 1; j >= 0; j--) cout << path[i][j] << " ";
            cout << endl;
        }
    }
    cout << endl;
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

