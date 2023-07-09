#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<LL> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    string s;
    cin >> s;
    s = ' ' + s;
    vector<LL> dp(n + 1);
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1];
        if (s[i] != s[i - 1] && dp[i - 2] + a[i] + a[i - 1] > dp[i]) {
            dp[i] = dp[i - 2] + a[i] + a[i - 1];
        }
    }
    cout << dp[n] << endl;
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