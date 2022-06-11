#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto& x: a) cin >> x;
    sort(a.begin(), a.end());
    vector<LL> sum(n);
    for (int i = 0; i < n; i++) {
        if (i == 0) sum[i] = a[i];
        else sum[i] = sum[i - 1] + a[i];
    }
    while (q--) {
        LL x;
        cin >> x;
        auto p = lower_bound(a.begin(), a.end(), x) - a.begin();
        if (p == 0) cout << sum[n - 1] - x * n << endl;
        else {
            LL l = x * p - sum[p - 1];
            LL r = sum[n - 1] - sum[p - 1] - x * (n - p);
            cout << l + r << endl;
        }
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

