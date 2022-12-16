#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<int> dp(n + 1, INT_MAX);
    dp[n] = 0;
    for (int i = n; i >= 0; i--) {
        if (dp[i] == INT_MAX) continue;
        int x = i;
        while (x) {
            if (dp[i] + 1 < dp[i - x % 10]) {
                dp[i - x % 10] = dp[i] + 1;
            }
            x /= 10;
        }
    }
    cout << dp[0] << endl;
}

int main() {
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}