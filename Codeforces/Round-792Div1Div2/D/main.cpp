#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<LL> a(n);
    LL res = 0;
    for (auto& x: a) {
        cin >> x;
        res += x;
    }
    for (int i = 0; i < n; i++) {
        a[i] = n - i - 1 - a[i];
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < k; i++) {
        res += a[i];
    }
    res -= 1ll * (k - 1) * k / 2;
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

