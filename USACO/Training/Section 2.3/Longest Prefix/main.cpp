/*
ID: frankzh1
TASK: prefix
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    set<string> P;
    string s;
    while (cin >> s) {
        if (s == ".") break;
        P.insert(s);
    }
    string S;
    while (cin >> s) {
        S += s;
    }
    int sz = S.size();
    vector<bool> dp(sz + 1, false);
    dp[0] = true;
    int res = 0;
    for (int i = 1; i <= sz; i++) {
        for (auto &s: P) {
            int j = i - s.size();
            if (j >= 0 && s == S.substr(j, s.size()) && dp[j]) {
                dp[i] = true;
                break;
            }
        }
        if (dp[i]) res = max(i, res);
    }
    cout << res << endl;
}

int main() {
    freopen("prefix.in", "r", stdin);
    freopen("prefix.out", "w", stdout);
    solve();
    return 0;
}

