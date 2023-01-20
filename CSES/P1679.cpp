#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    vector<int> deg(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        deg[v]++;
    }
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (!deg[i]) q.push(i);
    }
    vector<int> ans;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        ans.push_back(u + 1);
        for (auto v: g[u]) {
            deg[v]--;
            if (!deg[v]) {
                q.push(v);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (deg[i]) {
            cout << "IMPOSSIBLE" << endl;
            return;
        }
    }
    for (auto x: ans) cout << x << ' ';
    cout << endl;
}

int main() {
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}