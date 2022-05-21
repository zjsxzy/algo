#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    LL n;
    cin >> n;
    map<int, LL> cnt;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    LL res = n * (n - 1) * (n - 2) / 6;
    for (auto [k, v]: cnt) {
        if (v >= 3) res -= v * (v - 1) * (v - 2) / 6;
        if (v >= 2) res -= (v * (v - 1) / 2 * (n - v));
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

