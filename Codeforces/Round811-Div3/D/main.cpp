#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    string t;
    cin >> t;
    t = ' ' + t;
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    int sz = t.size(), inf = 1e9;
    vector<vector<int>> dp(m + 1, vector<int>(m + 1, inf));
    for (int l = 1; l <= sz; l++) {
        for (int i = 1; i + l - 1 <= sz; i++) {
            int j = i + l - 1;
            string subt = t.substr(i, l);
            bool f = false;
            for (auto ss: s) {
                if (subt == ss) {
                    f = true;
                    break;
                }
            }
            if (f) dp[i][j] = 1;
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("in.txt", "r", stdin);
#endif
   int ts = 1;
   cin >> ts;
   for (int t = 1; t <= ts; t++) {
       solve();
   }
   return 0;
}

