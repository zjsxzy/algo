#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, m, x, t, d;
    cin >> n >> m >> x >> t >> d;
    int st = t - d * x;
    if (m <= x) {
        cout << st + d * m << endl;
    } else {
        cout << t << endl;
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

