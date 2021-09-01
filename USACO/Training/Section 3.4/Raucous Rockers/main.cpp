/*
ID: frankzh1
TASK: rockers
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int MAXN = 25;
int dp[MAXN][MAXN][MAXN];
int a[MAXN];

void solve() {
    int n, t, m;
    cin >> n >> t >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 0; k <= t; k++) {
                dp[i][j][k] = dp[i - 1][j][k];
                if (k >= a[i]) {
                    dp[i][j][k] = max(dp[i][j][k], max(dp[i - 1][j - 1][t] + 1, dp[i - 1][j][k - a[i]] + 1));
                }
            }
        }
    }
    cout << dp[n][m][t] << endl;
}

int main() {
    freopen("rockers.in", "r", stdin);
    freopen("rockers.out", "w", stdout);
    solve();
    return 0;
}

