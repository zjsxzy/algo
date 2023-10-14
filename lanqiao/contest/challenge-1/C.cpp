#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> h(n);
    for (auto& x: h) cin >> x;
    sort(h.begin(), h.end());
    auto check = [&](int diff) {
        int group = 1, mn = h[0];
        for (int i = 1; i < n; i++) {
            if (h[i] - mn > diff) {
                group++;
                mn = h[i];
            }
        }
        // cout << diff << ' ' << group << endl;
        return group <= k;
    };
    int lo = 0, hi = 1e9, res = -1;
    while (lo <= hi) {
        int mid = (lo + hi) >> 1;
        if (check(mid)) hi = mid - 1, res = mid;
        else lo = mid + 1;
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