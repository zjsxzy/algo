#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int inf = 1e9;

void solve() {
    int n, m;
    cin >> n;
    vector<int> s(n);
    for (auto& x: s) cin >> x;
    cin >> m;
    vector<int> key(m);
    for (auto& x: key) cin >> x;
    map<int, vector<int>> pos;
    for (int i = 0; i < m; i++) {
        pos[key[i]].push_back(i);
    }
    vector<vector<int>> dp(n, vector<int>(m, inf));
    for (auto p: pos[s[0]]) dp[0][p] = 0;
    for (int i = 1; i < n; i++) {
        for (auto p: pos[s[i]]) {
            auto q = lower_bound(pos[s[i - 1]].begin(), pos[s[i - 1]].end(), p);
            if (q == pos[s[i - 1]].end()) {
                q--;
                dp[i][p] = min(dp[i][p], dp[i - 1][*q] + abs(p - *q));
            } else {
                dp[i][p] = min(dp[i][p], dp[i - 1][*q] + abs(p - *q));
                if (q != pos[s[i - 1]].end()) {
                    q--;
                    dp[i][p] = min(dp[i][p], dp[i - 1][*q] + abs(p - *q));
                }
            }
        }
    }
    int res = inf;
    for (auto p: pos[s[n - 1]]) {
        res = min(res, dp[n - 1][p]);
    }
    cout << res << endl;
}

int main() {
   int ts = 1;
   cin >> ts;
   for (int t = 1; t <= ts; t++) {
       cout << "Case #" << t << ": ";
       solve();
   }
   return 0;
}

