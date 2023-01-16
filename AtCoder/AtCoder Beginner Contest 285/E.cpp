#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<LL> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        b[i] = b[i - 1] + a[(i + 1) / 2];
    }
    vector<vector<LL>> dp(n + 1, vector<LL>(n + 1, -1e18));
    dp[1][0] = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (dp[i][j] >= 0) {
                dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j]);
                dp[i + 1][0] = max(dp[i + 1][0], dp[i][j] + b[j]);
            }
        }
    }
    LL res = 0;
    for (int j = 0; j < n; j++) {
        res = max(res, dp[n][j] + b[j]);
    }
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