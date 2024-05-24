#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n), w(n);
    for (int i = 0; i < n; i++) cin >> w[i] >> v[i];
    vector<int> dp((1 << 12));
    for (int i = 0; i < n; i++) {
        dp[w[i]] = v[i];
    }
    for (int i = 0; i < n; i++) {
        vector<int> newdp = dp;
        for (int j = 0; j < (1 << 12); j++) {
            newdp[j & w[i]] = max(newdp[j & w[i]], dp[j] & v[i]);
        }
        dp = newdp;
    }
    int res = 0;
    for (int j = 0; j <= k; j++) res = max(res, dp[j]);
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