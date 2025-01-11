#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x: a) cin >> x;
    LL res = 0;
    for (int i = 0; i < n; i++) {
        auto r = upper_bound(a.begin(), a.end(), a[i] / 2) - a.begin();
        r--;
        if (r >= 0 && a[r] <= a[i] / 2) {
            res += r + 1;
            // cout << r + 1 << '\n';
        }
    }
    cout << res << '\n';
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