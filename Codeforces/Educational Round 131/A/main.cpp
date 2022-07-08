#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int a[5][5];
void solve() {
    int n = 2, s = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            s += a[i][j];
        }
    }
    if (s == 0) {
        cout << 0 << endl;
    } else if (s == 4) {
        cout << 2 << endl;
    } else {
        cout << 1 << endl;
    }
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

