#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define MP make_pair
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int inf = 1e9;

void solve() {
    int n;
    cin >> n;
    vector<int> pos, a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i]) pos.push_back(i);
    }
    int m = pos.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, inf));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= m; j++) {
            if (dp[i][j] == inf) continue;
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
            if (a[i] == 0 && j < m) {
                dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + abs(pos[j] - i));
            }
        }
    }
    cout << dp[n][m] << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

