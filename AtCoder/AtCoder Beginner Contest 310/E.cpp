#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    vector dp(n, vector(2, 0ll));
    dp[0][0] = (s[0] == '0');
    dp[0][1] = (s[0] == '1');
    LL res = dp[0][1];
    for (int i = 1; i < n; i++) {
        if (s[i] == '0') {
            dp[i][1] = i;
            dp[i][0] = 1;
        } else {
            dp[i][1] = dp[i - 1][0] + 1;
            dp[i][0] = dp[i - 1][1];
        }
        res += dp[i][1];
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