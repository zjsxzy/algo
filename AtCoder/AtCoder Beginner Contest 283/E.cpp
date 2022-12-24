#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int inf = 1e9;
const int maxn = 1005;
int dp[maxn][2][2], A[maxn][maxn];

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
        }
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                dp[i][j][k] = inf;
            }
        }
    }
    dp[0][0][0] = 0;
    dp[0][0][1] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                for (int l = 0; l < 2; l++) {
                    bool ok = true;
                    for (int y = 0; y < m; y++) {
                        bool ok2 = false;
                        if (i > 0) {
                            if ((A[i][y] ^ k) == (A[i - 1][y] ^ j)) ok2 = true;
                        }
                        if (i < n - 1) {
                            if ((A[i][y] ^ k) == (A[i + 1][y] ^ l)) ok2 = true;
                        }
                        if (y > 0) {
                            if ((A[i][y] ^ k) == (A[i][y - 1] ^ k)) ok2 = true;
                        }
                        if (y < m - 1) {
                            if ((A[i][y] ^ k) == (A[i][y + 1] ^ k)) ok2 = true;
                        }
                        if (!ok2) ok = false;
                    }
                    if (ok) {
                        dp[i + 1][k][l] = min(dp[i + 1][k][l], dp[i][j][k] + l);
                    }
                }
            }
        }
    }
    int res = inf;
    for (int j = 0; j < 2; j++) {
        for (int k = 0; k < 2; k++) {
            res = min(res, dp[n][j][k]);
        }
    }
    if (res == inf) res = -1;
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