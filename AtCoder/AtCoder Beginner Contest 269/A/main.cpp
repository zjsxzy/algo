#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << (a + b) * (c - d) << endl;
    cout << "Takahashi" << endl;
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

