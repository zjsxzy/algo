#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> t(q);
    for (auto& x: t) cin >> x;
    t.push_back(0);
    // t.push_back(n);
    sort(t.begin(), t.end());
    vector<int> k(m), s(m);
    for (int i = 0; i < m; i++) {
        cin >> k[i] >> s[i];
    }
    vector<LL> dp(n + 1);
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1];
        auto x = lower_bound(t.begin(), t.end(), i);
        if (i == *x) continue;
        x--;
        // cout << i << ' ' << *x << endl;
        for (int j = 0; j < m; j++) {
            if (i - (1 << k[j]) >= *x) {
                // cout << i << ' ' << i - (1 << k[j]) << endl;
                dp[i] = max(dp[i], dp[i - (1 << k[j])] + s[j]);
            }
        }
        // cout << i << ' ' << dp[i] << endl;
    }
    cout << dp[n] << endl;
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