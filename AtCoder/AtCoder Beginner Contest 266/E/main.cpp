#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<double> dp(n);
    dp[0] = 3.5;
    for (int i = 1; i < n; i++) {
        double x = dp[i - 1];
        for (int j = 1; j <= 6; j++) {
            dp[i] += max((double)j, x) / 6;
        }
    }
    printf("%.10f\n", dp[n - 1]);
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

