#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int A, B;
    cin >> A >> B;
    int res = 0;
    for (int i = 0; i < 3; i++) {
        if (A >> i & 1 || B >> i & 1) res |= 1 << i;
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

