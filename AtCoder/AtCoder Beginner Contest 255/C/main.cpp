#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    LL X, A, D, N;
    cin >> X >> A >> D >> N;
    LL l = A, r = A + (N - 1) * D;
    if (l > r) swap(l, r);
    if (X <= l) {
        cout << l - X << endl;
        return;
    }
    if (X >= r) {
        cout << X - r << endl;
        return;
    }
    LL res = 1ll << 60;
    LL k = (X - A) / D;
    for (LL i = k - 2; i < min(N, k + 5); i++) {
        LL Y = A + D * i;
        res = min(res, abs(X - Y));
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

