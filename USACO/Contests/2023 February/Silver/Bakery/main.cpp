#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    LL tc, tm;
    cin >> n >> tc >> tm;
    vector<LL> a(n), b(n), c(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i] >> c[i];
    auto calc = [&](LL A, LL B, LL C, LL k) {
        if (C - B * k == 0) return true;
        if (A - B == 0) return C - B * k >= 0;
        if (C - B * k < 0 && A - B > 0) return false;
        if (C - B * k > 0 && A - B < 0) return true;
        if (C - B * k > 0 && A - B > 0) return true;
        if (C - B * k < 0 && A - B < 0) {
            LL t = (C - B * k) / (A - B);
            if ((C - B * k) % (A - B) != 0) t++;
            return (t <= k) && (t <= tc);
        }
        return true;
    };
    auto check = [&](LL x) {
        for (int i = 0; i < n; i++) {
            cout << a[i] << ' ' << b[i] << ' ' << c[i] << ' ' << x << endl; 
            if (!calc(a[i], b[i], c[i], x)) return false;
        }
        return true;
    };
    cout << check(6) << endl;
    // cout << calc(4, 3, 18, 7) << endl;
    // cout << calc(2, 4, 19, 7) << endl;
    // cout << calc(1, 1, 6, 7) << endl;
    return;
    LL lo = 0, hi = tc + tm, res;
    while (lo <= hi) {
        LL mid = (lo + hi) >> 1;
        if (check(mid)) {
            res = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    cout << max(tc + tm - res, 0ll) << endl;
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