#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const LL inf = 1ll << 60;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(m), b(m), c(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i] >> c[i];
        a[i]--; b[i]--;
    }
    vector<LL> dp(n, inf);
    dp[0] = 0;
    for (int i = 0; i < k; i++) {
        int e;
        cin >> e;
        e--;
        dp[b[e]] = min(dp[b[e]], dp[a[e]] + c[e]);
    }
    if (dp[n - 1] == inf) {
        cout << -1 << endl;
    } else {
        cout << dp[n - 1] << endl;
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

