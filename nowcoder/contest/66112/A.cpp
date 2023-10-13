#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    string s;
    int n, k;
    cin >> n >> k >> s;
    const int inf = 1e9;
    vector<vector<int>> dp(n, vector<int>(n, inf));
    for (int i = 0; i < n; i++) {
        dp[i][i] = 0;
        if (i + 1 < n && s[i] == s[i + 1]) dp[i][i + 1] = 0;
    }
    for (int l = 3; l <= n; l++) {
        for (int i = 0; i + l - 1 < n; i++) {
            int j = i + l - 1;
            if (s[i] == s[j]) {
                dp[i][j] = min(dp[i][j], dp[i + 1][j - 1]);
                if (dp[i + 1][j] != inf) {
                    dp[i][j] = min(dp[i][j], dp[i + 1][j] + 1);
                }
                if (dp[i][j - 1] != inf) {
                    dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
                }
            }
        }
    }
    int res = k - 1;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int t = dp[i][j] + j - i + 1;
            res = min(res, dp[i][j] + max(0, k - t));
        }
    }
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