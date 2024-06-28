#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 1005;
const int mod = 1e9 + 7;
int dp[maxn][maxn], sumdp[maxn][maxn];

void solve() {
    int n, x;
    cin >> n >> x;
    int m = 0;
    memset(dp, 0, sizeof(dp));
    memset(sumdp, 0, sizeof(dp));
    for (;m * m <= x; m++);
    m--;
    for (int j = 1; j <= m; j++) {
        dp[1][j] = 1;
        sumdp[1][j] = sumdp[1][j - 1] + dp[1][j];
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] += sumdp[i - 1][j - 1];
            dp[i][j] %= mod;
        }
        for (int j = 1; j <= m; j++) {
            sumdp[i][j] = sumdp[i][j - 1] + dp[i][j];
            sumdp[i][j] %= mod;
        }
    }
    cout << sumdp[n][m] << endl;
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