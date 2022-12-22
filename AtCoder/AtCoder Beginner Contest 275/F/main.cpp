#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 3005;
const int inf = 1e9;
int dp[maxn][maxn][2], a[maxn];

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            dp[i][j][0] = dp[i][j][1] = inf;
        }
    }
    dp[0][0][1] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            dp[i][j][0] = min(dp[i - 1][j][0], dp[i - 1][j][1] + 1);
            if (j - a[i] >= 0) {
                dp[i][j][1] = min(dp[i - 1][j - a[i]][0], dp[i - 1][j - a[i]][1]);
            }
        }
    }
    for (int j = 1; j <= m; j++) {
        int res = min(dp[n][j][0], dp[n][j][1]);
        if (res == inf) res = -1;
        cout << res << endl;
    }
    
}

int main() {
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}