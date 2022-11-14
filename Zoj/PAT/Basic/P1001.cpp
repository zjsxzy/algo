#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int f(int x) {
    if (x == 1) return 0;
    if (x % 2 == 0) return f(x / 2) + 1;
    return f((3 * x + 1) / 2) + 1;
}

void solve() {
    int n;
    cin >> n;
    cout << f(n) << endl;
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

