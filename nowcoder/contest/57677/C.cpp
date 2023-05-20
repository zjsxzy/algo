#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x: a) cin >> x;
    vector e(n, vector(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> e[i][j];
        }
    }
    vector<int> sum(1 << n);
    for (int s = 1; s < (1 << n); s++) {
        for (int i = 0; i < n; i++) if (s >> i & 1) sum[s] += a[i];
    }
    vector dp(1 << n, vector(n, 1e9));
    for (int i = 0; i < n; i++) dp[1 << i][i] = 0;
    LL res = 1e18;
    for (int s = 1; s < (1 << n); s++) {
        int b = __builtin_ctz(s);
        for (int u = b; u < n; u++) {
            if (dp[s][u] == 1e9) continue;
            if (__builtin_popcount(s) > 2 && e[u][b]) {
                LL t = (LL)sum[s] * (dp[s][u] + e[u][b]);
                res = min(res, t);
            }
            for (int v = b; v < n; v++) {
                if (!(s >> v & 1) && e[u][v]) {
                    dp[s | (1 << v)][v] = min(dp[s | (1 << v)][v], dp[s][u] + e[u][v]);
                }
            }
        }
    }
    if (res == 1e18) res = -1;
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