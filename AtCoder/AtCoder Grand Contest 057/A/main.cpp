#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int l, r;
    cin >> l >> r;
    int res = 0;
    for (int d = (int)1e9; d >= 1; d /= 10) {
        if (d <= r) {
            if (d <= l) res += r - l + 1;
            else {
                res += r - d + 1;
                int rr = d - 1;
                l = max(l, r - d + 1);
                l = max(l, r / 10 + 1);
                l = max(l, d / 10);
                if (l < d) res += rr - l + 1;
            }
            break;
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

