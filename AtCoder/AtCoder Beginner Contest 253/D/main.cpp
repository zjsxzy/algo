#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    LL n, a, b;
    cin >> n >> a >> b;
    LL l = a * b / gcd(a, b);
    LL res = n * (n + 1) / 2;
    LL d = n / a;
    res -= a * (d * (d + 1) / 2);
    d = n / b;
    res -= b * (d * (d + 1) / 2);
    d = n / l;
    res += l * (d * (d + 1) / 2);
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

