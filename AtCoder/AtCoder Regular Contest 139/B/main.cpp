#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

LL f(LL n, LL a, LL y, LL x) {
    if (x * a < y) return n * x;
    return (n / a) * y + (n % a) * x;
}

void solve() {
    LL n, a, b, x, y, z;
    cin >> n >> a >> b >> x >> y >> z;
    LL res = 1e18;
    if (a > 30000) {
        for (int j = 0; 1LL * j * a <= n; j++) {
            res = min(res, f(n - j * a, b, z, x) + 1LL * j * y);
        }
    } else {
        if (1LL * z * a < 1LL * y * b) {
            swap(a, b); swap(y, z);
        }
        for (int k = 0; k <= a && 1LL * k * b <= n; k++) {
            res = min(res, f(n - k * b, a, y, x) + 1LL * k * z);
        }
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

