#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    LL n, k;
    cin >> n >> k;
    auto sum = [&](LL s) {
        if (s <= n + 1) {
            return s * (s - 1) / 2;
        } else {
            // res += (s - n) * n;
            // LL t = n - (s - n);
            // res += (n - 1 + n - t) * t / 2;
                    long long ret = 1LL * (1 + n) * n / 2;
        long long first = n - 1, last = n - (s - (n + 1));
        return ret + (first + last) * (first - last + 1) / 2;
        }
    };
    LL lo = 2, hi = n * 2, s;
    while (lo <= hi) {
        LL mid = (lo + hi) >> 1;
        if (sum(mid) >= k) s = mid, hi = mid - 1;
        else lo = mid + 1;
    }
    // cout << s << endl;
    LL r = sum(s) - k;
    if (s >= n + 1) cout << n - r << ' ' << s - (n - r) << endl;
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