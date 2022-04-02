#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

LL calc(LL a, LL b) {
    return (a + b) * (a * a + b * b);
}

void solve() {
    LL n;
    cin >> n;
    LL res = 1e18;
    for (LL a = 0; a <= 1e6; a++) {
        LL lo = 0, hi = 1e6;
        while (lo <= hi) {
            LL mid = (lo + hi) >> 1;
            LL t = calc(a, mid);
            if (t >= n) {
                res = min(res, t);
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
    }
    cout << res << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

