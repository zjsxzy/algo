#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    LL n, x;
    cin >> n >> x;
    vector<LL> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    LL res = 1LL << 60, minb = 1LL << 60, sum = 0;
    for (int i = 0; i < n; i++) {
        minb = min(minb, b[i]);
        sum += a[i] + b[i];
        res = min(res, sum + (x - i - 1) * minb);
    }
    cout << res << endl;
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

