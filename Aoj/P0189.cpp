#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 10;
const int inf = 1e6;
int d[maxn][maxn];

void solve() {
    int m;
    while (cin >> m) {
        if (m == 0) break;
        for (int i = 0; i < maxn; i++) {
            for (int j = 0; j < maxn; j++) {
                if (i == j) d[i][j] = 0;
                else d[i][j] = inf;
            }
        }
        int n = 0;
        while (m--) {
            int u, v, w;
            cin >> u >> v >> w;
            d[u][v] = d[v][u] = min(d[u][v], w);
            n = max(n, max(u, v));
        }
        n++;
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
        vector<int> sum(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                sum[i] += d[i][j];
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (sum[i] < sum[ans]) ans = i;
        }
        cout << ans << ' ' << sum[ans] << endl;
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