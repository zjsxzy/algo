/*
ID: frankzh1
TASK: nocows
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int mod = 9901;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    for (int i = 1; i <= m; i++) {
        dp[i][1] = 1;
    }
    for (int i = 2; i <= m; i++) {
        for (int j = 3; j <= n; j += 2) {
            for (int k = 1; k < j; k += 2) {
                dp[i][j] += dp[i - 1][k] * dp[i - 1][j - k - 1];
                dp[i][j] %= mod;
            }
        }
    }
    cout << (dp[m][n] - dp[m - 1][n] + mod) % mod << endl;
}

int main() {
    freopen("nocows.in", "r", stdin);
    freopen("nocows.out", "w", stdout);
    solve();
    return 0;
}

