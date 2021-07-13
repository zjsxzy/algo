#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define sz(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const LL mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> h(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    vector<vector<LL>> dp(n + 1, vector<LL>(n + 1, 0));
    vector<LL> sum(n + 1, 0);
    dp[1][1] = 1;
    // 被动转移
    /*
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (h[i] == h[i - 1]) dp[i][j] = sum[i - 1];
            else if (h[i] < h[i - 1]) {
                dp[i][j] = (sum[i - 1] - sum[j - 1] + mod) % mod;
            } else {
                dp[i][j] = sum[j - 1];
            }
        }
        for (int j = 1; j <= n; j++) {
            sum[j] = (sum[j - 1] + dp[i][j]) % mod;
        }
    }
    */
    // 主动转移
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= i; j++) {
            sum[j] = (sum[j - 1] + dp[i][j]) % mod;
        }
        for (int j = 1; j <= i + 1; j++) {
            if (h[i] == h[i + 1]) dp[i + 1][j] = sum[i];
            else if (h[i] < h[i + 1]) {
                dp[i + 1][j] = (sum[i] - sum[j - 1] + mod) % mod;
            } else {
                dp[i + 1][j] = sum[j - 1];
            }
        }
    }
    LL res = 0;
    for (int j = 1; j <= n; j++) {
        res = (res + dp[n][j]) % mod;
    }
    cout << res << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

