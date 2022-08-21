#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int x, y, n;
    cin >> x >> y >> n;
    int res = INT_MAX;
    for (int i = 0; 3 * i <= n; i++) {
        res = min(res, i * y + (n - i * 3) * x);
    }
    cout << res << endl;
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

