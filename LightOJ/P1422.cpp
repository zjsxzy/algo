#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) dp[i][i] = 1;
    for (int l = 1; l < n; l++) {
        for (int i = 1; i + l <= n; i++) {
            int j = i + l;
            dp[i][j] = dp[i][j - 1] + 1; // buy a new one
            for (int k = i; k < j; k++) {
                if (a[k] == a[j]) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j - 1]);
                }
            }
        }
    }
    cout << dp[1][n] << endl;
}

int main() {
    int ts = 1;
    cin >> ts;
    for (int t = 1; t <= ts; t++) {
        cout << "Case " << t << ": ";
        solve();
    }
    return 0;
}