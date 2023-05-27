#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    LL x, y, z;
    cin >> x >> y >> z;
    string s;
    cin >> s;
    s = "#" + s;
    int n = s.size();
    LL inf = 1ll << 60, cnt = 0;
    LL dp[n][2];
    for (int i = 1; i < n; i++) dp[i][0] = dp[i][1] = inf;
    dp[0][0] = 0;
    dp[0][1] = z;
    for (int i = 1; i < n; i++) {
        cnt++;
        if (i == n - 1 || s[i] != s[i + 1]) {
            if (s[i] == 'a') {
                dp[i][0] = min(dp[i][0], dp[i - cnt][0] + x * cnt);
                dp[i][1] = min(dp[i][1], dp[i - cnt][1] + y * cnt);
                dp[i][0] = min(dp[i][0], dp[i - cnt][1] + z + x * cnt);
            } else { // s[i] == A
                dp[i][1] = min(dp[i][1], dp[i - cnt][1] + x * cnt);
                dp[i][0] = min(dp[i][0], dp[i - cnt][0] + y * cnt);
                dp[i][1] = min(dp[i][1], dp[i - cnt][0] + z + x * cnt);
            }
            cnt = 0;
            dp[i][0] = min(dp[i][0], dp[i][1] + z);
            dp[i][1] = min(dp[i][1], dp[i][0] + z);
        }
        // cout << i << ' ' << dp[i][0] << ' ' << dp[i][1] << endl;
    }
    cout << min(dp[n - 1][0], dp[n - 1][1]) << endl;
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