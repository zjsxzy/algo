#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> w(n);
    for (int i = 0; i < n; i++) cin >> w[i];
    const int inf = n + 1;
    vector<pair<int, int>> dp(1 << n, {inf, 0});
    dp[0] = {0, x};
    for (int s = 0; s < (1 << n); s++) {
        if (dp[s].first == inf) continue;
        for (int i = 0; i < n; i++) {
            if (s >> i & 1) continue;
            if (dp[s].second + w[i] <= x) {
                dp[s | (1 << i)] = min(dp[s | (1 << i)], {dp[s].first, dp[s].second + w[i]});
            } else {
                dp[s | (1 << i)] = min(dp[s | (1 << i)], {dp[s].first + 1, min(dp[s].second, w[i])});
            }
        }
    }
    cout << dp[(1 << n) - 1].first << endl;
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