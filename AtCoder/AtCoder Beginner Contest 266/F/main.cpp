#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<int> deg(n);
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++; deg[v]++;
    }
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (deg[i] == 1) q.push(i);
    }
    set<int> tree;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        tree.insert(u);
        for (auto v: adj[u]) {
            deg[v]--;
            if (deg[v] == 1) {
                q.push(v);
            }
        }
    }

    int color = 0;
    vector<int> id(n);
    function<void(int, int)> dfs = [&](int u, int c) {
        id[u] = c;
        for (auto v: adj[u]) {
            if (tree.count(v) && !id[v]) {
                dfs(v, c);
            }
        }
    };
    for (int i = 0; i < n; i++) {
        if (tree.count(i)) continue;
        color++;
        dfs(i, color);
    }

    int query;
    cin >> query;
    while (query--) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        if (id[u] == id[v]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("in.txt", "r", stdin);
#endif
   int ts = 1;
   // cin >> ts;
   for (int t = 1; t <= ts; t++) {
       solve();
   }
   return 0;
}

