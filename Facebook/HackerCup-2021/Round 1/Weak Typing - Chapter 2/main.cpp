#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int inf = 1 << 29;
const int mod = 1e9 + 7;
void solve() {
    int n;
    cin >> n;
    string str;
    cin >> str;
    vector<vector<int>> dp(n + 1, vector<int>(2));
    vector<vector<LL>> sum(n + 1, vector<LL>(2));
    for (int i = 1; i <= n; i++) {
        char c = str[i - 1];
        if (c == 'F') {
            // dp[i][0] = min(dp[i - 1][0], dp[i - 1][1] + 1);
            if (dp[i - 1][1] + 1 < dp[i - 1][0]) {
                dp[i][0] = dp[i - 1][1] + 1;
                sum[i][0] = (sum[i - 1][1] + (i - 1)) % mod;
            } else {
                dp[i][0] = dp[i - 1][0];
                sum[i][0] = sum[i - 1][0];
            }
            // dp[i][1] = min(dp[i - 1][0] + 1, dp[i - 1][1]);
            if (dp[i - 1][0] + 1 < dp[i - 1][1]) {
                dp[i][1]=  dp[i - 1][0] + 1;
                sum[i][1] = (sum[i - 1][0] + (i - 1)) % mod;
            } else {
                dp[i][1] = dp[i - 1][1];
                sum[i][1] = sum[i - 1][1];
            }
        } else if (c == 'X') {
            // dp[i][0] = min(dp[i - 1][0], dp[i - 1][1] + 1);
            if (dp[i - 1][1] + 1 < dp[i - 1][0]) {
                dp[i][0] = dp[i - 1][1] + 1;
                sum[i][0] = (sum[i - 1][1] + (i - 1)) % mod;
            } else {
                dp[i][0] = dp[i - 1][0];
                sum[i][0] = sum[i - 1][0];
            }
            dp[i][1] = inf;
            sum[i][1] = sum[i - 1][1];
        } else if (c == 'O') {
            dp[i][0] = inf;
            sum[i][0] = sum[i - 1][0];
            //dp[i][1] = min(dp[i - 1][0] + 1, dp[i - 1][1]);
            if (dp[i - 1][0] + 1 < dp[i - 1][1]) {
                dp[i][1] = dp[i - 1][0] + 1;
                sum[i][1] = (sum[i - 1][0] + (i - 1)) % mod;
            } else {
                dp[i][1] = dp[i - 1][1];
                sum[i][1] = sum[i - 1][1];
            }
        }
    }
    LL res = 0;
    for (int i = 1; i <= n; i++) {
        if (dp[i][0] < dp[i][1]) {
            res = (res + sum[i][0]) % mod;
        } else {
            res = (res + sum[i][1]) % mod;
        }
    }
    cout << res << endl;
}

int main() {
    int ts;
    cin >> ts;
    for (int i = 1; i <= ts; i++) {
        printf("Case #%d: ", i);
        solve();
    }
    return 0;
}

