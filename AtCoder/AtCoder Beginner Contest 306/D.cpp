#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<int> x(n + 1), y(n + 1);
    for (int i = 1; i <= n; i++) cin >> x[i] >> y[i];
    vector<vector<LL>> dp(n + 1, vector<LL>(2));
    for (int i = 1; i <= n; i++) {
        // skip
        for (int j = 0; j < 2; j++) {
            dp[i][j] = dp[i - 1][j];
        }
        // eat
        if (x[i] == 0) {
            // cout << i << ' ' << dp[i - 1][0] + y[i] << ' ' << dp[i - 1][1] + y[i] << endl;
            dp[i][0] = max(dp[i][0], dp[i - 1][0] + y[i]);
            dp[i][0] = max(dp[i][0], dp[i - 1][1] + y[i]);
        } else {
            dp[i][1] = max(dp[i][1], dp[i - 1][0] + y[i]);
        }
        // cout << i << ' ' << x[i] << ' ' << dp[i][0] << ' ' << dp[i][1] << endl;
    }
    cout << max(dp[n][0], dp[n][1]) << endl;
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