#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    LL m;
    cin >> m;
    auto sum = [&](LL k) {
        return 1ll * k * (k + 1) * (k + 2) / 6;
    };
    LL lo = 1, hi = 2e6, res;
    while (lo <= hi) {
        LL mid = (lo + hi) >> 1;
        if (sum(mid) <= m) {
            res = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    cout << res + 1 << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int ts = 1;
    cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}