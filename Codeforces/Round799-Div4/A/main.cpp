#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int res = 0;
    if (b > a) res++;
    if (c > a) res++;
    if (d > a) res++;
    cout << res << endl;
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

