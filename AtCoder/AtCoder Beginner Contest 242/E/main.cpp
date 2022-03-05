#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const LL mod = 998244353;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    int m = (n - 1) / 2;
    vector<LL> dp(m + 1);
    dp[0] = s[0] - 'A' + 1;
    for (int i = 1; i <= m; i++) {
        dp[i] += (dp[i - 1] - 1) * 26;
        dp[i] %= mod;

        dp[i] += s[i] - 'A' + 1;
        dp[i] %= mod;
    }
    auto t = s;
    for (int i = 0; i < n / 2; i++) {
        t[n - i - 1] = s[i];
    }
    LL res = dp[m];
    if (t > s) {
        res += mod - 1;
        res %= mod;
    }
    cout << res << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int ts;
    cin >> ts;
    while (ts--) {
        solve();
    }
    return 0;
}

