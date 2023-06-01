#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    s = ' ' + s;
    const int mod = 1e9 + 7;
    vector dp(n + 1, vector(3, 0)), sumdp(n + 1, vector(3, 0));
    dp[0][0] = sumdp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '6') {
            for (int j = 0; j < 3; j++) {
                dp[i][1] += sumdp[i - 1][j];
                dp[i][1] %= mod;
            }
        } else if (s[i] == '1') {
            dp[i][2] += sumdp[i - 1][0];
            dp[i][2] %= mod;
            dp[i][2] += sumdp[i - 1][2];
            dp[i][2] %= mod;
        } else {
            for (int j = 0; j < 3; j++) {
                dp[i][0] += sumdp[i - 1][j];
                dp[i][0] %= mod;
            }
        }
        for (int j = 0; j < 3; j++) {
            sumdp[i][j] = sumdp[i - 1][j] + dp[i][j];
            sumdp[i][j] %= mod;
            // cout << i << ' ' << j << ' ' << dp[i][j] << endl;
        }
    }
    int res = 0;
    for (int j = 0; j < 3; j++) {
        res += sumdp[n][j];
        res %= mod;
    }
    cout << res - 1 << endl;
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