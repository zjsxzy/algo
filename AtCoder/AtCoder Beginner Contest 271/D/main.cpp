#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, s;
    cin >> n >> s;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];
    vector<vector<int>> dp(n + 1, vector<int>(s + 1));
    vector<vector<int>> prev(n + 1, vector<int>(s + 1));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= s; j++) {
            if (j - a[i] >= 0 && dp[i - 1][j - a[i]]) {
                dp[i][j] = 1;
                prev[i][j] = j - a[i];
            }
            if (j - b[i] >= 0 && dp[i - 1][j - b[i]]) {
                dp[i][j] = 1;
                prev[i][j] = j - b[i];
            }
        }
    }
    string ans(n + 1, 'X');
    function<void(int, int)> output = [&](int i, int j) {
        if (i == 0) return;
        if (j - prev[i][j] == a[i]) ans[i] = 'H';
        else ans[i] = 'T';
        output(i - 1, prev[i][j]);
    };
    if (dp[n][s]) {
        cout << "Yes" << endl;
        output(n, s);
        cout << ans.substr(1, n) << endl;
    } else {
        cout << "No" << endl;
    }
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

