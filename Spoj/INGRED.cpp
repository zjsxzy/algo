#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n, vector<int>(n, 1e9));
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u][v] = g[v][u] = w;
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (g[i][k] + g[k][j] < g[i][j]) g[i][j] = g[i][k] + g[k][j];
            }
        }
    }
    int s;
    cin >> s;
    vector<int> store(s);
    for (int i = 0; i < s; i++) {
        cin >> store[i];
    }
    int s1, s2;
    cin >> s1 >> s2;
    int res = 1e9, state = 0;
    for (int i = 0; i < s; i++) {
        if (store[i] == s1 || store[i] == s2) state |= (1 << i);
    }
    function<void(int, int, int, int)> dfs = [&](int st, int u, int v, int dist) {
        if (st == (1 << s) - 1) {
            res = min(res, dist);
            return;
        }
        for (int i = 0; i < s; i++) {
            if (st >> i & 1) continue;
            dfs(st | (1 << i), store[i], v, dist + g[u][store[i]]);
            dfs(st | (1 << i), u, store[i], dist + g[v][store[i]]);
        }
    };
    dfs(state, s1, s2, 0);
    cout << res << endl;
}

int main() {
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}