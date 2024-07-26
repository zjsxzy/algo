#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int mod = 1e9 + 7;
const int MAXN = 100005;
int dp[MAXN][25], sumdp[MAXN][25], a[MAXN];

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    memset(dp, 0, sizeof(dp));
    memset(sumdp, 0, sizeof(sumdp));
    for (int i = 1; i <= n; i++) cin >> a[i];
    // dp[0][0] = 1;
    // sumdp[0][0] = 1;
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         dp[i][j] = sumdp[i - 1][j];
    //     }
    //     for (int j = 0; j < m; j++) {
    //         dp[i][(j + a[i]) % m] += sumdp[i - 1][j];
    //         dp[i][(j + a[i]) % m] %= mod;
    //     }
    //     for (int j = 0; j < m; j++) {
    //         sumdp[i][j] += dp[i][j];
    //         sumdp[i][j] %= mod;
    //     }
    // }
    // for (int i = 1; i <= n; i++) cout << sumdp[i][0] << ' ';
    // cout << endl;
    // for (int i = 1; i <= n; i++) cout << dp[i][0] << ' ';
    // cout << endl;
    while (q--) {
        int l, r;
        cin >> l >> r;
        dp[l - 1][0] = sumdp[l - 1][0] = 1;
        for (int j = 1; j < m; j++) dp[l - 1][j] = sumdp[l - 1][j] = 0;
        for (int i = l; i <= r; i++) {
            for (int j = 0; j < m; j++) {
                dp[i][j] = sumdp[i][j] = 0;
            }
            for (int j = 0; j < m; j++) {
                dp[i][j] = sumdp[i - 1][j];
            }
            for (int j = 0; j < m; j++) {
                dp[i][(j + a[i]) % m] += sumdp[i - 1][j];
                dp[i][(j + a[i]) % m] %= mod;
            }
            for (int j = 0; j < m; j++) {
                sumdp[i][j] += dp[i][j];
                sumdp[i][j] %= mod;
            }
        }
        // for (int i = l; i <= r; i++) {
        //     cout << i << ' ' << dp[i][0] << endl;
        // }
        cout << dp[r][0] << endl;
        // cout << sumdp[r][0] - sumdp[l][0] << endl;
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