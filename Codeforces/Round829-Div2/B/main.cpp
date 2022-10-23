#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    for (int i = 1, j = n / 2 + 1; i <= n / 2; i++, j++) {
        cout << j << ' ' << i << ' ';
    }
    if (n & 1) cout << n << endl;
    else cout << endl;
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

