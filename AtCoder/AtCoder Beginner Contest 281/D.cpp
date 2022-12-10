#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL dp[105][105][105];
void solve() {
    int n, k, d;
    cin >> n >> k >> d;
    vector<int> a(n);
    for (auto& x: a) cin >> x;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++) dp[i][0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            for (int r = 0; r < d; r++) {
                if (dp[i][j][r] == -1) continue;
                if (dp[i][j][r] > dp[i + 1][j][r]) {
                    dp[i + 1][j][r] = dp[i][j][r];
                }
                if (dp[i][j][r] + a[i] > dp[i + 1][j + 1][(r + a[i]) % d]) {
                    dp[i + 1][j + 1][(r + a[i]) % d] = dp[i][j][r] + a[i]; 
                }
                // cout << i << ' ' << j << ' ' << r << ' ' << dp[i][j][r] << endl;
            }
        }
    }
    cout << dp[n][k][0] << endl;
}

int main() {
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}