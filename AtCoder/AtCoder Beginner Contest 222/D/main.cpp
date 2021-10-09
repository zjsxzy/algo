#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const LL mod = 998244353;
const int maxn = 3005;
LL a[maxn], b[maxn], sum[maxn];
LL dp[maxn][maxn];

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    for (int j = a[1]; j <= b[1]; j++) {
        dp[1][j] = 1;
    }
    sum[0] = dp[1][0];
    for (int j = 1; j <= 3000; j++) {
        sum[j] = sum[j - 1] + dp[1][j];
    }
    for (int i = 2; i <= n; i++) {
        for (int j = a[i]; j <= b[i]; j++) {
            dp[i][j] = sum[j];
            // cout << i << " " << j << " " << dp[i][j] << endl;
        }
        sum[0] = dp[i][0];
        for (int j = 1; j <= 3000; j++) {
            sum[j] = (sum[j - 1] + dp[i][j]) % mod;
        }
    }
    int res = 0;
    for (int j = a[n]; j <= b[n]; j++) {
        res = (res + dp[n][j]) % mod;
    }
    cout << res << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

