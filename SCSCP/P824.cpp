#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    std::cin >> n;
    vector g(n, vector(n, 0));
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) std::cin >> g[i][j];
    vector dp(1 << n, 0);
    dp[0] = 1;
    const int mod = 1e9 + 7;
    for (int i = 0; i < n; i++) {
        vector ndp = dp;
        for (int s = 0; s < (1 << n); s++) {
            if (dp[s]) {
                for (int j = 0; j < n; j++) {
                    if (!(s >> j & 1) && g[i][j]) {
                        ndp[s | (1 << j)] += dp[s];
                        ndp[s | (1 << j)] %= mod;
                    }
                }
            }
        }
        dp = ndp;
    }
    std::cout << dp[(1 << n) - 1] << endl;
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