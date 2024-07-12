#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, L, R;
    cin >> n >> L >> R;
    string s;
    cin >> s;
    s = '#' + s;
    vector sum(2, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        sum[0][i] = sum[0][i - 1] + (s[i] == '0');
        sum[1][i] = sum[1][i - 1] + (s[i] == '1');
    }
    vector dp(n + 1, vector<LL>(n + 1));
    for (int l = 2; l <= n; l++) {
        for (int i = 1; i <= n; i++) {
            int j = i + l - 1;
            if (j > n) continue;
            for (int k = i; k < j; k++) {
                int diff = abs((sum[0][k] - sum[0][i - 1]) - (sum[1][j] - sum[1][k])); 
                if (L <= diff && diff <= R) {
                    // cout << i << ' ' << k << ' ' << j << ' ' << diff << ' ' << sum[0][k] - sum[0][i - 1] << ' ' << sum[1][j] - sum[1][k] << endl;
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[k + 1][j] + 1);
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