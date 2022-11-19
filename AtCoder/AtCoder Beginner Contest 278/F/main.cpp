#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    vector<vector<int>> dp(1 << n, vector<int>(n));
    for (int mask = (1 << n) - 1; mask >= 0; mask--) {
        for (int u = 0; u < n; u++) {
            if (mask >> u & 1) {
                for (int v = 0; v < n; v++) {
                    if (!(mask >> v & 1) && s[u].back() == s[v][0] && !dp[mask | (1 << v)][v]) {
                        dp[mask][u] = 1;
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (!dp[1 << i][i]) {
            cout << "First" << endl;
            return;
        }
    }
    cout << "Second" << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}

