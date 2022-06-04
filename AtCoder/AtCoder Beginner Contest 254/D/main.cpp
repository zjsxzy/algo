#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<int> cnt(n + 1);
    for (int x = 1; x <= n; x++) {
        int k = x;
        for (int d = 2; d * d <= k; d++) {
            if (k % (d * d) == 0) {
                k /= d * d;
                while (k % (d * d) == 0) {
                    k /= (d * d);
                }
            }
        }
        cnt[k]++;
    }
    LL res = 0;
    for (int i = 1; i <= n; i++) {
        res += 1ll * cnt[i] * cnt[i];
    }
    cout << res << '\n';
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

