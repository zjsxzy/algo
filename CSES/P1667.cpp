#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
 
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    while (m--) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> dist(n, INT_MAX), prev(n, -1);
    dist[0] = 0;
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto v: g[u]) {
            if (dist[v] == INT_MAX) {
                dist[v] = dist[u] + 1;
                prev[v] = u;
                q.push(v);
            }
        }
    }
    if (dist[n - 1] == INT_MAX) cout << "IMPOSSIBLE" << endl;
    else {
        cout << dist[n - 1] + 1 << endl;
        vector<int> ans;
        ans.push_back(n - 1);
        int u = n - 1;
        while (prev[u] != -1) {
            ans.push_back(prev[u]);
            u = prev[u];
        }
        reverse(ans.begin(), ans.end());
        for (auto x: ans) cout << x + 1 << ' ';
        cout << endl;
    }
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