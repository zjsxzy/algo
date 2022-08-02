#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    string t;
    cin >> t;
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    int sz = t.size(), inf = 1e9;
    vector<int> dp(sz + 1, inf);
    vector<vector<pair<int, int>>> res(sz + 1);
    dp[0] = 0;
    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k <= i; k++) {
                if (k + s[j].size() > i && k + s[j].size() <= sz && t.substr(k, s[j].size()) == s[j]) {
                    if (dp[i] + 1 < dp[k + s[j].size()]) {
                        dp[k + s[j].size()] = dp[i] + 1;
                        res[k + s[j].size()] = res[i];
                        res[k + s[j].size()].push_back({j, k});
                    }
                }
            }
        }
    }
    if (dp[sz] == inf) cout << -1 << endl;
    else {
        cout << dp[sz] << endl;
        for (auto [x, y]: res[sz]) {
            cout << x + 1 << ' ' << y + 1 << endl;
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

