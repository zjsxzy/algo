#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 255;
const int inf = 1e9;
int dp[maxn][maxn][maxn];
int a[maxn];

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    reverse(a, a + n);
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int k = 0; k <= m; k++) {
                dp[i][j][k] = inf;
            }
        }
    }
    dp[0][0][0] = 0;
    int sum = 0;
    for (int pos = 0; pos < n; pos++) {
        sum += a[pos];
        for (int oldsum = 0; oldsum <= m; oldsum++) {
            for (int last = 0; last <= oldsum; last++) {
                for (int next = last; next <= m; next++) {
                    if (next + oldsum > m) break;
                    int t = dp[pos][oldsum][last] + abs(oldsum + next - sum);
                    if (t < dp[pos + 1][oldsum + next][next]) {
                        dp[pos + 1][oldsum + next][next] = t;
                    }
                }
            }
        }
    }
    int res = inf;
    for (int i = 0; i <= m; i++) res = min(res, dp[n][m][i]);
    cout << res << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

