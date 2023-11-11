#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    LL n, k;
    cin >> n >> k;
    auto sum = [&](LL s) {
        LL res = 0;
        if (s == 1) return res;
        if (s <= n) {
            res = s * (s - 1) / 2;
            return res;
        } else {
            res += (s - n) * n;
            LL t = n - (s - n);
            res += (n - 1 + n - t) * t / 2;
        }
        return res;
    };
    LL lo = 1, hi = n * n, s;
    while (lo <= hi) {
        LL mid = (lo + hi) >> 1;
        if (sum(mid) >= k) s = mid, hi = mid - 1;
        else lo = mid + 1;
    }
    // cout << s << endl;
    LL r = sum(s) - k;
    if (s > n) cout << n - r << ' ' << s - (n - r) << endl;
    else cout << s - (r + 1) << ' ' << r + 1 << endl;
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