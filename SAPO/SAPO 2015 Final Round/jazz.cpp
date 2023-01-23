#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    s = ' ' + s;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) dp[i][i] = 1;
    for (int l = 1; l < n; l++) {
        for (int i = 1; i + l <= n; i++) {
            int j = i + l;
            dp[i][j] = dp[i][j - 1] + 1;
            for (int k = i; k < j; k++) {
                if (s[k] == s[j]) {
                    dp[i][j] = min(dp[i][j], dp[i][k - 1] + dp[k + 1][j - 1]);
                }
            }
        }
    }
    cout << dp[1][n] << endl;
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