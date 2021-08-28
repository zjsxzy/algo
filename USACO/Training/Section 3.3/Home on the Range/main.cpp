/*
ID: frankzh1
TASK: range
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
    vector<string> mat(n);
    vector<vector<int>> dp(n, vector<int>(n));
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        cin >> mat[i];
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == '0') continue;
            if (i == 0 || j == 0) {
                dp[i][j] = 1;
                continue;
            }
            dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
            for (int k = 2; k <= dp[i][j]; k++) {
                cnt[k]++;
            }
        }
    }
    for (auto &[k, v]: cnt) {
        cout << k << " " << v << endl;
    }
}

int main() {
    freopen("range.in", "r", stdin);
    freopen("range.out", "w", stdout);
    solve();
    return 0;
}

