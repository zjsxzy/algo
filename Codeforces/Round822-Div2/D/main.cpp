#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
   int n, k;
   cin >> n >> k;
   vector<int> a(n + 1);
   for (int i = 1; i <= n; i++) cin >> a[i];
   int i = k - 1, j = k + 1;
   LL val = a[k];
   LL lsum = 0, rsum = 0, lmax = 0, rmax = 0;
   while (1) {
       if (i == 0 || j == n + 1) {
           cout << "YES" << endl;
           return;
       }
       if (val + lsum + rmax + a[i] >= 0) {
           lsum += a[i];
           i--;
           lmax = max(lmax, lsum);
       } else if (val + rsum + lmax + a[j] >= 0) {
           rsum += a[j];
           j++;
           rmax = max(rmax, rsum);
       } else break;
   }
   cout << "NO" << endl;
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

