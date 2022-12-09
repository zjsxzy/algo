#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    const LL inf = 1ll << 60;
    vector<vector<LL>> d(n, vector<LL>(n, inf));
    for (int i = 0; i < m; i++) {
        int u, v;
        LL w;
        cin >> u >> v >> w;
        u--; v--;
        d[u][v] = d[v][u] = min(d[u][v], w);
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (d[i][k] + d[k][j] < d[i][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }
    for (int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        if (u == v) cout << 0 << endl;
        else if (d[u][v] == inf) cout << -1 << endl;
        else cout << d[u][v] << endl;
    }
}

int main() {
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}