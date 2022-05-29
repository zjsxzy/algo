#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    if (a <= b && b <= c) {
        cout << "Yes" << '\n';
        return;
    }
    if (a >= b && b >= c) {
        cout << "Yes" << '\n';
        return;
    }
    cout << "No" << '\n';
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

