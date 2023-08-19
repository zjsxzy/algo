#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    vector deg(n, 0);
    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        while (c--) {
            int j;
            cin >> j;
            j--;
            g[i].push_back(j);
            deg[j]++;
        }
    }
    vector<int> conn(n);
    function<void(int)> dfs = [&](int u) {
        conn[u] = 1;
        for (auto v: g[u]) {
            if (conn[v]) continue;
            dfs(v);
        }
    };
    dfs(0);
    for (int i = 0; i < n; i++) {
        if (!conn[i]) {
            for (auto v: g[i]) {
                deg[v]--;
            }
        }
    }
    for (auto v: g[0]) {
        deg[v]--;
    }
    vector<int> ans;
    queue<int> q;
    for (int i = 1; i < n; i++) {
        if (deg[i] == 0 && conn[i]) q.push(i);
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        ans.push_back(u);
        for (auto v: g[u]) {
            deg[v]--;
            if (deg[v] == 0 && conn[v]) {
                q.push(v);
            }
        }
    }
    reverse(ans.begin(), ans.end());
    for (auto x: ans) cout << x + 1 << ' ';
    cout << endl;
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