/*
ID: frankzh1
TASK: subset
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<vector<LL>> dp(n + 1, vector<LL>(n * (n + 1) / 2 + 1));
    dp[1][0] = dp[1][1] = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= i * (i + 1) / 2; j++) {
            if (dp[i][j]) {
                dp[i + 1][j] += dp[i][j];
                dp[i + 1][j + i + 1] += dp[i][j];
            }
        }
    }
    if (n * (n + 1) % 4 == 0) cout << dp[n][n * (n + 1) / 4] / 2 << endl;
    else cout << 0 << endl;
}

int main() {
    freopen("subset.in", "r", stdin);
    freopen("subset.out", "w", stdout);
    solve();
    return 0;
}

