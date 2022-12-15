#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<int> dp(n + 1);
    const int mod = 1e9 + 7;
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int d = 1; d <= 6; d++) {
            if (i - d >= 0) {
                dp[i] += dp[i - d];
                dp[i] %= mod;
            }
        }
    }
    cout << dp[n] << endl;
}

int main() {
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}