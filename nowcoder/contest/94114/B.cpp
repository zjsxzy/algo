#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int mod = 1e9 + 7;
void solve() {
    int x, y;
    cin >> x >> y;
    y++;
    vector dp(y + 1, vector<int>(2005, 0));
    int m = 2000, base = 1000;
    dp[0][base] = 1;
    for (int i = 0; i < y; i++) {
        for (int j = 0; j <= m; j++) {
            if (dp[i][j] == 0) continue;
            // one hand
            for (int k = 1; k <= 10; k++) {
                if (j + k >= 0 && j + k <= m) {
                    dp[i + 1][j + k] += dp[i][j];
                    dp[i + 1][j + k] %= mod;
                }
                if (j - k >= 0 && j - k <= m) {
                    dp[i + 1][j - k] += dp[i][j];
                    dp[i + 1][j - k] %= mod;
                }
            }
            // two hand
            for (int a = 1; a <= 5; a++) {
                for (int b = 1; b <= 5; b++) {
                    if (j + a + b >= 0 && j + a + b <= m) {
                        dp[i + 1][j + a + b] += dp[i][j];
                        dp[i + 1][j + a + b] %= mod;
                    }
                    if (j + a - b >= 0 && j + a - b <= m) {
                        dp[i + 1][j + a - b] += dp[i][j];
                        dp[i + 1][j + a - b] %= mod;
                    }
                    if (j - a + b >= 0 && j - a + b <= m) {
                        dp[i + 1][j - a + b] += dp[i][j];
                        dp[i + 1][j - a + b] %= mod;
                    }
                    if (j - a - b >= 0 && j - a - b <= m) {
                        dp[i + 1][j - a - b] += dp[i][j];
                        dp[i + 1][j - a - b] %= mod;
                    }
                }
            }
        }
    }
    cout << dp[y][base + x] << endl;
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