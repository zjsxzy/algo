#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int inf = 1 << 29;
void solve() {
    int n;
    cin >> n;
    string str;
    cin >> str;
    vector<vector<int>> dp(n + 1, vector<int>(2));
    for (int i = 1; i <= n; i++) {
        char c = str[i - 1];
        if (c == 'F') {
            dp[i][0] = min(dp[i - 1][0], dp[i - 1][1] + 1);
            dp[i][1] = min(dp[i - 1][0] + 1, dp[i - 1][1]);
        } else if (c == 'X') {
            dp[i][0] = min(dp[i - 1][0], dp[i - 1][1] + 1);
            dp[i][1] = inf;
        } else if (c == 'O') {
            dp[i][0] = inf;
            dp[i][1] = min(dp[i - 1][0] + 1, dp[i - 1][1]);
        }
    }
    int res = min(dp[n][0], dp[n][1]);
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

