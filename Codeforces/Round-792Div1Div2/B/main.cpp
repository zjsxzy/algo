#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    LL a, b, c;
    cin >> a >> b >> c;
    cout << a + b * c << " " << b << " " << c << '\n';
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

