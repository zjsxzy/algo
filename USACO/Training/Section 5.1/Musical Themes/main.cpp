/*
ID: frankzh1
TASK: theme
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
    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
    }
    int res = 0;
    vector<vector<int>> dp(2, vector<int>(n));
    for (int j = 1; j < n; j++) {
        dp[0][j] = 1;
    }
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] - a[i - 1] == a[j] - a[j - 1] && dp[(i - 1) % 2][j - 1] + 1 <= j - i) {
                dp[i % 2][j] = dp[(i - 1) % 2][j - 1] + 1;
            } else {
                dp[i % 2][j] = 1;
            }
            res = max(res, dp[i % 2][j]);
        }
    }
    if (res < 5) res = 0;
    cout << res << endl;
}

int main() {
    freopen("theme.in", "r", stdin);
    freopen("theme.out", "w", stdout);
    solve();
    return 0;
}

