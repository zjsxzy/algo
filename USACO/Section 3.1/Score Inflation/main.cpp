/*
ID: frankzh1
TASK: inflate
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    int m, n;
    cin >> m >> n;
    vector<int> p(n), t(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i] >> t[i];
    }
    vector<int> dp(m + 1);
    for (int i = 0; i < n; i++) {
        for (int j = t[i]; j <= m; j++) {
            dp[j] = max(dp[j], dp[j - t[i]] + p[i]);
        }
    }
    cout << dp[m] << endl;
}

int main() {
    freopen("inflate.in", "r", stdin);
    freopen("inflate.out", "w", stdout);
    solve();
    return 0;
}

