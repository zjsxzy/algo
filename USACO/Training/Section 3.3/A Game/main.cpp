/*
ID: frankzh1
TASK: game1
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
    vector<int> a(n + 1), sum(n + 1);
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
        dp[i][i] = a[i];
    }
    for (int l = 1; l <= n; l++) {
        for (int i = 1; i <= n; i++) {
            int j = i + l;
            if (j > n) continue;
            dp[i][j] = max(sum[j] - sum[i] - dp[i + 1][j] + a[i], sum[j - 1] - sum[i - 1] - dp[i][j - 1] + a[j]);
        }
    }
    cout << dp[1][n] << " " << sum[n] - dp[1][n] << endl;
}

int main() {
    freopen("game1.in", "r", stdin);
    freopen("game1.out", "w", stdout);
    solve();
    return 0;
}

