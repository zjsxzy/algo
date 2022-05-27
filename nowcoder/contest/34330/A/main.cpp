#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    int mx = 0, res, a = 0;
    for (auto& [k, v]: cnt) {
        a += v;
        int b = n - a;
        if (cnt.find(k + 1) != cnt.end()) b -= cnt[k + 1];
        if (min(a, b) > mx) {
            mx = min(a, b);
            res = k + 1;
        }
    }
    cout << mx << " " << res << '\n';
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

