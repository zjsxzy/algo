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
            LL res = 0;
            res += (s - n) * n;
            LL t = n - (s - n);
            res += (n - 1 + n - t) * t / 2;
            return res;
        }
    };
    LL lo = 2, hi = n * 2, s;
    while (lo <= hi) {
        LL mid = (lo + hi) >> 1;
        if (sum(mid) >= k) s = mid, hi = mid - 1;
        else lo = mid + 1;
    }
    // cout << s << endl;
    LL a = k - sum(s - 1);
    if (s > n) a += s - n - 1;
    cout << a << ' ' << s - a << endl;
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