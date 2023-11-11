#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 1005;
int g[maxn][maxn];
LL dp[maxn][maxn][4];

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> g[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    dp[1][1][q] = g[1][1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 0; k <= q; k++) {
                if (dp[i][j][k] == -1) continue;
                if (i + 1 <= n) {
                    if (gcd(g[i][j], g[i + 1][j]) == 1) {
                        if (k > 0) dp[i + 1][j][k - 1] = max(dp[i + 1][j][k - 1], dp[i][j][k] + g[i + 1][j]);
                    } else {
                        dp[i + 1][j][k] = max(dp[i + 1][j][k], dp[i][j][k] + g[i + 1][j]);
                    }
                }
                if (j + 1 <= m) {
                    if (gcd(g[i][j], g[i][j + 1]) == 1) {
                        if (k > 0) dp[i][j + 1][k - 1] = max(dp[i][j + 1][k - 1], dp[i][j][k] + g[i][j + 1]);
                    } else {
                        dp[i][j + 1][k] = max(dp[i][j + 1][k], dp[i][j][k] + g[i][j + 1]);
                    }
                }
            }
        }
    }
    LL res = dp[n][m][0];
    for (int k = 1; k <= q; k++) res = max(res, dp[n][m][k]);
    cout << res << endl;
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
}#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 1005;
int g[maxn][maxn];
LL dp[maxn][maxn][4];

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> g[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    dp[1][1][q] = g[1][1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 0; k <= q; k++) {
                if (dp[i][j][k] == -1) continue;
                if (i + 1 <= n) {
                    if (gcd(g[i][j], g[i + 1][j]) == 1) {
                        if (k > 0) dp[i + 1][j][k - 1] = max(dp[i + 1][j][k - 1], dp[i][j][k] + g[i + 1][j]);
                    } else {
                        dp[i + 1][j][k] = max(dp[i + 1][j][k], dp[i][j][k] + g[i + 1][j]);
                    }
                }
                if (j + 1 <= m) {
                    if (gcd(g[i][j], g[i][j + 1]) == 1) {
                        if (k > 0) dp[i][j + 1][k - 1] = max(dp[i][j + 1][k - 1], dp[i][j][k] + g[i][j + 1]);
                    } else {
                        dp[i][j + 1][k] = max(dp[i][j + 1][k], dp[i][j][k] + g[i][j + 1]);
                    }
                }
            }
        }
    }
    LL res = dp[n][m][0];
    for (int k = 1; k <= q; k++) res = max(res, dp[n][m][k]);
    cout << res << endl;
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