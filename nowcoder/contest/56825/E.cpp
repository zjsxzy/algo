#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, m, k, q;
    cin >> n >> m >> k >> q;
    vector<LL> a(n), b(m), c(k);
    for (auto& x: a) cin >> x;
    for (auto& x: b) cin >> x;
    for (int i = 0; i < k; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        c[i] = a[u] * b[v];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    auto count = [&](LL x) {
        // # < x
        LL res = 0;
        for (int i = 0; i < n; i++) {
            if (x % a[i] == 0) {
                int cnt = lower_bound(b.begin(), b.end(), x / a[i]) - b.begin();
                res += cnt;
            } else {
                int cnt = upper_bound(b.begin(), b.end(), x / a[i]) - b.begin();
                res += cnt;
            }
        }
        int cnt = lower_bound(c.begin(), c.end(), x) - c.begin();
        return res - cnt;
    };
    while (q--) {
        int t;
        cin >> t;
        LL lo = 1, hi = 1e18, res;
        while (lo <= hi) {
            LL mid = (lo + hi) >> 1;
            if (count(mid) <= t - 1) {
                res = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        cout << res << endl;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}