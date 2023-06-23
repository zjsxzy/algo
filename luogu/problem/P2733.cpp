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
    vector<int> cnt(n + 1);
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
    for (int i = 2; i <= n; i++) {
        if (cnt[i] > 0) {
            cout << i << " " << cnt[i] << endl;
        }
    }
}

int main() {
    solve();
    return 0;
}

