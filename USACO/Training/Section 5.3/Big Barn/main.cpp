/*
ID: frankzh1
TASK: bigbrn
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n + 1, vector<int>(n + 1)), dp(n + 1, vector<int>(n + 1));
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        a[x][y] = 1;
    }
    int res = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            if (a[i][j]) continue;
            dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
            res = max(res, dp[i][j]);
        }
    cout << res << endl;
}

int main() {
    freopen("bigbrn.in", "r", stdin);
    freopen("bigbrn.out", "w", stdout);
    solve();
    return 0;
}

