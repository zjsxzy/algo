#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    LL L, R, sum = 0;
    cin >> n >> L >> R;
    vector<LL> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    vector<LL> f(n + 1);
    for (int i = 1; i <= n; i++) {
        f[i] = min(f[i - 1] + a[i], L * i);
    }
    LL res = min(sum, f[n]);
    for (int i = 1; i <= n; i++) {
        res = min(res, f[i - 1] + R * (n - i + 1));
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

