#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int mod = 1e9 + 7;
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> dp(k);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        vector<int> newdp(k);
        for (int j = 0; j < k; j++) {
            newdp[(j + x) % k] += dp[j];
            newdp[(j + x) % k] %= mod;
            newdp[j] += dp[j];
            newdp[j] %= mod;
        }
        dp = newdp;
    }
    cout << (dp[0] + mod - 1) % mod << endl;
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