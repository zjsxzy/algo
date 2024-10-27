#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    int unknown = -999, base = 50;
    for (auto& x: a) {
        cin >> x;
        if (x != unknown) x += base;
    }
    vector dp(n, vector<int>(101, -1));
    if (a[0] != unknown) {
        dp[0][a[0]] = 0;
    } else {
        for (int j = 0; j <= 100; j++) dp[0][j] = 0;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= 100; j++) {
            if (dp[i - 1][j] == -1) continue;
            if (a[i] != unknown) {
                dp[i][a[i]] = max(dp[i][a[i]], dp[i - 1][j] + (j - a[i] >= x));
            } else {
                for (int k = 0; k <= 100; k++) {
                    dp[i][k] = max(dp[i][k], dp[i - 1][j] + (j - k >= x));
                }
            }
        }
    }
    if (a[n - 1] != unknown) cout << dp[n - 1][a[n - 1]] << ' ';
    else {
        int res = 0;
        for (int j = 0; j <= 100; j++) {
            res = max(res, dp[n - 1][j]);
        }
        cout << res << ' ';
    }

    dp.clear();
    dp.assign(n, vector<int>(101, n + 1));
    if (a[0] != unknown) {
        dp[0][a[0]] = 0;
    } else {
        for (int j = 0; j <= 100; j++) dp[0][j] = 0;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= 100; j++) {
            if (dp[i - 1][j] == n + 1) continue;
            if (a[i] != unknown) {
                dp[i][a[i]] = min(dp[i][a[i]], dp[i - 1][j] + (j - a[i] >= x));
            } else {
                for (int k = 0; k <= 100; k++) {
                    dp[i][k] = min(dp[i][k], dp[i - 1][j] + (j - k >= x));
                }
            }
        }
    }
    if (a[n - 1] != unknown) cout << dp[n - 1][a[n - 1]] << endl;
    else {
        int res = n;
        for (int j = 0; j <= 100; j++) {
            res = min(res, dp[n - 1][j]);
        }
        cout << res << endl;
    }
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