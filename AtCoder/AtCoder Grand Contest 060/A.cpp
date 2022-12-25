#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int mod = 998244353;
int dp[5005][26][26];

void solve() {
    int n;
    string s;
    cin >> n >> s;
    memset(dp, 0, sizeof(dp));
    for (int j = 0; j < 26; j++) {
        if (s[0] != '?' && s[0] - 'a' != j) continue;
        for (int k = 0; k < 26; k++) {
            if (s[1] != '?' && s[1] - 'a' != k) continue;
            if (j == k) continue;
            dp[1][j][k] = 1;
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 26; j++) {
            if (s[i - 1] != '?' && s[i - 1] - 'a' != j) continue;
            for (int k = 0; k < 26; k++) {
                if (dp[i][j][k] == 0) continue;
                if (s[i] != '?' && s[i] - 'a' != k) continue;
                for (int l = 0; l < 26; l++) {
                    if (i + 1 < n && s[i + 1] != '?' && s[i + 1] - 'a' != l) continue;
                    if (j != k && k != l && j != l) {
                        dp[i + 1][k][l] += dp[i][j][k];
                        dp[i + 1][k][l] %= mod;
                    }
                }
            }
        }
    }
    int res = 0;
    for (int j = 0; j < 26; j++) {
        for (int k = 0; k < 26; k++) {
            res += dp[n - 1][j][k];
            res %= mod;
        }
    }
    cout << res << endl;
}

int main() {
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}