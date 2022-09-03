#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<LL> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<vector<LL>> dp(n + 1, vector<LL>(n + 1));
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
        for (int j = 1; j <= m; j++) {
            dp[i][j] = -(1ll << 60);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + a[i] * j);
        }
    }
    LL res = -(1ll << 60);
    for (int i = m; i <= n; i++) {
        res = max(res, dp[i][m]);
    }
    cout << res << endl;
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("in.txt", "r", stdin);
#endif
   int ts = 1;
   // cin >> ts;
   for (int t = 1; t <= ts; t++) {
       solve();
   }
   return 0;
}

