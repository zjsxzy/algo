#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MOD = 998244353;
int dp[105][105][105];
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x: a) cin >> x;
    int res = n;
    for (int m = 2; m <= n; m++) {
        vector<int> b(n);
        for (int i = 0; i < n; i++) b[i] = a[i] % m;
        memset(dp, 0, sizeof(dp));
        dp[0][0][0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                for (int k = 0; k <= m; k++) {
                    if (dp[i][j][k] > 0) {
                        dp[i + 1][j][k] += dp[i][j][k];
                        dp[i + 1][j][k] %= MOD;
                        dp[i + 1][j + 1][(k + b[i]) % m] += dp[i][j][k];
                        dp[i + 1][j + 1][(k + b[i]) % m] %= MOD;
                    }
                }
            }
        }
        res += dp[n][m][0];
        res %= MOD;
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

