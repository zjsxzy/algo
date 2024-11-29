#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for (auto& x: a) cin >> x;
    sort(a.begin(), a.end());
    a.resize(unique(a.begin(), a.end()) - a.begin());
    n = a.size();
    auto calc = [&](int l, int r) {
        int L = a[l], R = a[r];
        int range = R - L + 1;
        return range - (r - l + 1);
    };
    int res = 0;
    for (int i = 0; i < n; i++) {
        int lo = i, hi = n - 1, p;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            if (calc(i, mid) <= k) {
                p = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        int cnt = calc(i, p);
        int x = (i == 0) ? a[i] - 1 : a[i] - a[i - 1] - 1;
        int y = (p == n - 1) ? m - a[p] : a[p + 1] - a[p] - 1;
        res = max(res, min(cnt + x + y, k) + p - i + 1);
    }
    cout << res << endl;
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