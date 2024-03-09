#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    string T;
    cin >> T;
    int n;
    cin >> n;
    vector<vector<string>> S(n + 1);
    for (int i = 1; i <= n; i++) {
        int m;
        cin >> m;
        for (int j = 0; j < m; j++) {
            string s;
            cin >> s;
            S[i].push_back(s);
        }
    }
    int sz = T.size();
    vector<vector<int>> dp(n + 1, vector<int>(sz + 1, (int)1e9));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= sz; j++) dp[i][j] = dp[i - 1][j];
        for (int j = 0; j <= sz; j++) {
            for (auto s: S[i]) {
                int m = s.size();
                if (j - m >= 0 && s == T.substr(j - m, m) && dp[i - 1][j - m] + 1 < dp[i][j]) {
                    dp[i][j] = dp[i - 1][j - m] + 1;
                } 
            }
        }
    }
    if (dp[n][sz] == (int)1e9) cout << -1 << endl;
    else cout << dp[n][sz] << endl;
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