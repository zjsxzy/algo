#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int n, m;
vector<vector<int>> adj;
vector<int> vst;

void dfs(int u, int p) {
    vst[u] = true;
    for (auto v: adj[u]) {
        if (v == p || vst[v]) continue;
        cout << u + 1 << " " << v + 1 << endl;
        dfs(v, u);
    }
}

void bfs(int st) {
    vst.assign(n, 0);
    queue<int> q;
    q.push(st);
    vst[st] = true;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto v: adj[u]) {
            if (!vst[v]) {
                cout << u + 1 << " " << v + 1 << endl;
                vst[v] = true;
                q.push(v);
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    adj.assign(n, {});
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vst.assign(n, 0);
    dfs(0, -1);
    bfs(0);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

