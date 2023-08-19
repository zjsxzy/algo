#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    int m = 30;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
    const double inf = 1e9;
    vector dp(n, vector(m, inf));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = i + 1; k < n && j + k - i - 1 < m; k++) {
                int nj = j + k - i - 1;
                dp[k][nj] = min(dp[k][nj], dp[i][j] + sqrt((x[i] - x[k]) * (x[i] - x[k]) + (y[i] - y[k]) * (y[i] - y[k])));
            }
        }
    }
    double res = dp[n - 1][0];
    for (int j = 1; j < m; j++) {
        res = min(res, dp[n - 1][j] + (1 << (j - 1)));
    }
    cout << fixed << setprecision(10) << res << endl;
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