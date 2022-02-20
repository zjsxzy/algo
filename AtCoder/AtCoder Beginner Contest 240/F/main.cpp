#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    int n, m;
    cin >> n >> m;
    LL a = 0, b = 0, res = LLONG_MIN;
    for (int i = 0; i < n; i++) {
        LL x, y;
        cin >> x >> y;
        auto f = [&](LL k) {
            return a + b * k + x * k * (k + 1) / 2;
        };
        res = max(res, f(1));
        res = max(res, f(y));
        if (x) {
            LL mid = -(x + 2 * b) / (2 * x);
            for (int d = -1; d <= 1; d++) {
                if (mid + d >= 1 && mid + d <= y) {
                    res = max(res, f(mid + d));
                }
            }
        }
        a = f(y);
        b += x * y;
    }
    cout << res << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int ts;
    cin >> ts;
    while (ts--) {
        solve();
    }
    return 0;
}

