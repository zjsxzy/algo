#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(k);
    for (int i = 0; i < k; i++) cin >> a[i];
    vector<int> f(n + 1);
    f[n] = 0;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < k; j++) {
            if (i + a[j] > n) continue;
            f[i] = max(f[i], n - (i + a[j]) - f[i + a[j]] + a[j]);
        }
    }
    cout << f[0] << endl;
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

