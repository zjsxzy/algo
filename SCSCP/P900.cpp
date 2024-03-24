#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, k;
    cin >> n >> k;
    string S, T;
    cin >> S >> T;
    // int res = 0;
    // for (int i = 0, j = 0; i < n; ) {
    //     if (S[i] != T[i]) {
    //         for (j = i + 1; j < n; j++) {
    //             if (S[j] == T[j] || S[j] != S[i]) {
    //                 break;
    //             }
    //         }
    //         res += (j - i + k - 1) / k;
    //         i = j;
    //     } else {
    //         i++;
    //     }
    // }
    // cout << res << endl;
    S = '#' + S;
    T = '#' + T;
    const int inf = 1e9;
    vector<int> dp(n + 1, inf);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        int f = (S[i] == T[i] ? 0 : 1);
        for (int j = 1; j <= k; j++) {
            if (i - j < 0) break;
            // cout << i << ' ' << i - j << ' ' << dp[i - j] << ' ' << f << endl;
            dp[i] = min(dp[i], dp[i - j] + f);
            if (T[i - j] != T[i]) break;
            if (T[i - j] != S[i - j]) f = 1;
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