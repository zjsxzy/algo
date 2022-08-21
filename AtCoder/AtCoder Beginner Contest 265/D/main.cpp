#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    LL P, Q, R;
    cin >> n >> P >> Q >> R;
    vector<LL> a(n), sum(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum[i + 1] = sum[i] + a[i];
    }
    for (int x = 0; x <= n; x++) {
        int y = lower_bound(sum.begin(), sum.end(), P + sum[x]) - sum.begin();
        if (x < y && y <= n && sum[y] - sum[x] == P) {
            int z = lower_bound(sum.begin(), sum.end(), Q + sum[y]) - sum.begin();
            if (y < z && z <= n && sum[z] - sum[y] == Q) {
                int w = lower_bound(sum.begin(), sum.end(), R + sum[z]) - sum.begin();
                if (z < w && w <= n && sum[w] - sum[z] == R) {
                    // cout << x << ' ' << y << ' ' << z << ' ' << w << endl;
                    cout << "Yes" << endl;
                    return;
                }
            }
        }
    }
    cout << "No" << endl;
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

