#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 1005;
LL a[maxn][maxn], f[maxn][maxn], g[maxn][maxn];

void solve() {
    int n, m;
    cin >> n >> m;
    memset(a, 0, sizeof(a));
    LL inf = 1e16;
    for (int i = 0; i <= n + 1; i++) for (int j = 0; j <= m + 1; j++) f[i][j] = -inf;
    for (int i = 0; i <= n + 1; i++) for (int j = 0; j <= m + 1; j++) g[i][j] = -inf;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> a[i][j];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == 1 && j == 1) f[i][j] = a[i][j];
            else f[i][j] = max(f[i - 1][j], f[i][j - 1]) + a[i][j];
        }
    }
    for (int i = n; i >= 1; i--) {
        for (int j = m; j >= 1; j--) {
            if (i == n && j == m) g[i][j] = a[i][j];
            else g[i][j] = max(g[i + 1][j], g[i][j + 1]) + a[i][j];
        }
    }
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        vector<int> x(k), y(k);
        for (int i = 0; i < k; i++) cin >> x[i] >> y[i];
        LL res = f[n][m];
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                if (i == j) continue;
                res = max(res, f[x[i]][y[i]] + g[x[j]][y[j]]);
            }
        }
        cout << res << endl;
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