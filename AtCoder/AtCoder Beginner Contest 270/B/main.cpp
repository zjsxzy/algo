#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int x, y, z;
    cin >> x >> y >> z;
    if (x * y > 0 && abs(y) < abs(x)) {
        if (y * z > 0 && abs(y) < abs(z)) {
            cout << -1 << endl;
        } else {
            cout << abs(z) + abs(x - z) << endl;
        }
    } else {
        cout << abs(x) << endl;
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

