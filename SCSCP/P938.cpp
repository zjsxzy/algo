#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector a(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    vector dp(1 << n, vector<int>(n, -1));
    dp[1 << 0][0] = 0;
    for (int s = 1; s < (1 << n); s++) {
        for (int u = 0; u < n; u++) {
            if (dp[s][u] == -1) continue;
            for (int v = 0; v < n; v++) {
                if (s >> v & 1) continue;
                if (dp[s][u] + a[u][v] > dp[s | (1 << v)][v]) {
                    dp[s | (1 << v)][v] = dp[s][u] + a[u][v];
                }
            }
        }
    }
    int res = -1;
    for (int u = 1; u < n; u++) {
        res = max(res, dp[(1 << n) - 1][u] + a[u][0]);
    }
    cout << res << endl;
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
