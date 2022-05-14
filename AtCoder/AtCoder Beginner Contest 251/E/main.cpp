#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 300005;
const LL inf = (1ll << 60);
LL a[maxn];
LL dp[maxn][2][2];

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 2; j++) {
            dp[i][j][0] = dp[i][j][1] = inf;
        }
    }
    dp[1][0][0] = 0;
    dp[1][1][1] = a[1];
    for (int i = 2; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            dp[i][0][j] = min(dp[i][0][j], dp[i - 1][1][j]);
            dp[i][1][j] = min({dp[i - 1][0][j], dp[i - 1][1][j]}) + a[i];
        }
        // cout << i << " " << dp[i][0][1] << " " << dp[i][1][1] << endl;
    }
    LL res = min({dp[n - 1][1][1], dp[n - 1][0][1] + a[n], dp[n - 1][0][0] + a[n], dp[n - 1][1][0] + a[n]});
    cout << res << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

