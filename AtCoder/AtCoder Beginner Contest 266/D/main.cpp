#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const LL inf = 1ll << 60;

void solve() {
    int n;
    cin >> n;
    vector<int> t(n), x(n), a(n);
    int m = 0;
    for (int i = 0; i < n; i++) {
        cin >> t[i] >> x[i] >> a[i];
        m = max(m, t[i]);
    }
    vector<vector<LL>> dp(m + 1, vector<LL>(5, -inf));
    vector<vector<LL>> sum(m + 1, vector<LL>(5));
    for (int i = 0; i < n; i++) {
        sum[t[i]][x[i]] += a[i];
    }
    dp[0][0] = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = -1; k <= 1; k++) {
                if (j + k >= 0 && j + k < 5) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j + k] + sum[i][j]);
                }
            }
        }
    }
    LL res = -inf;
    for (int j = 0; j < 5; j++) res = max(res, dp[m][j]);
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

