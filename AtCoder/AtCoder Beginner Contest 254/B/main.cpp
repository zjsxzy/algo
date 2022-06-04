#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int a[33][33];
void solve() {
    int n;
    cin >> n;
    memset(a, 0, sizeof(a));
    a[1][1] = 1;
    for (int i = 2; i <= n; i++) {
        a[i][1] = 1;
        for (int j = 2; j <= i; j++)
            a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << a[i][j] << ' ';
        }
        cout << endl;
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

