#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int a[5][5];
void solve() {
    int r, c;
    cin >> r >> c;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> a[i][j];
        }
    }
    cout << a[r - 1][c - 1] << endl;
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

