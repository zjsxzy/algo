#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int maxn = 5005;
LL a[maxn], dp[maxn][maxn][2];

void solve() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    dp[1][1][1] = a[1];
    dp[2][1][0] = a[2];
    for (int i = 3; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            dp[i][j][0] = dp[i - 1][j][0];
            dp[i][j][1] = dp[i - 1][j][1];
            if (j > 0) {
                dp[i][j][0] = max(dp[i][j][0], dp[i - 2][j - 1][0] + a[i]);
                dp[i][j][1] = max(dp[i][j][1], dp[i - 2][j - 1][1] + a[i]);
            }
        }
    }
    dp[n][k][0] = dp[n - 1][k][0];
    dp[n][k][1] = dp[n - 1][k][1];
    dp[n][k][0] = max(dp[n][k][0], dp[n - 2][k - 1][0] + a[n]);
    cout << max(dp[n][k][0], dp[n][k][1]) << endl;
}

int main() {
    solve();
    return 0;
}

