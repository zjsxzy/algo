#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << 1 << endl;
        return;
    }
    int res = n;
    int g = n / 3;
    res += g * 4;
    int G = n / 2;
    res += (G - g) * 2;
    cout << res << endl;
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

