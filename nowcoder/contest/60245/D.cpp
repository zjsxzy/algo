#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int mod = 1e9 + 7;

void solve() {
    string s;
    std::cin >> s;
    int n = s.size();
    vector dp(n + 1, vector(9, 0ll));
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 9; j++) {
            if (dp[i][j] == 0) continue;
            dp[i + 1][j] += dp[i][j];
            dp[i + 1][j] %= mod;
            dp[i + 1][(j + s[i] - '0') % 9] += dp[i][j];
            dp[i + 1][(j + s[i] - '0') % 9] %= mod;
            // cout << i + 1 << ' ' << j << ' ' << dp[i][j] << endl;
        }
    }
    std::cout << (dp[n][0] - 1 + mod) % mod << endl;
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