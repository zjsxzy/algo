#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL dist(LL x1, LL y1, LL x2, LL y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(k), x(n), y(n);
    for (int i = 0; i < k; i++) {
        cin >> a[i];
        a[i]--;
    }
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    LL res = 0;
    for (int i = 0; i < n; i++) {
        LL d = 1ll << 60;
        for (int j = 0; j < k; j++) {
            d = min(d, dist(x[i], y[i], x[a[j]], y[a[j]]));
        }
        res = max(res, d);
    }
    double ans = sqrt(res);
    printf("%.9f\n", ans);
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

