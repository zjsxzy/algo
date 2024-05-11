#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x: a) cin >> x;
    sort(a.begin(), a.end());
    vector<LL> sum(n);
    sum[0] = a[0];
    for (int i = 1; i < n; i++) sum[i] = sum[i - 1] + a[i];
    LL res = 0;
    int M = 1e8;
    for (int i = 0; i < n; i++) {
        int x = a[i];
        auto j = lower_bound(a.begin(), a.end(), M - x) - a.begin();
        if (j > i) {
            res += sum[j - 1] - sum[i] + (LL)(j - i - 1) * x;
            res += sum[n - 1] - sum[j - 1] + (LL)(n - j) * (x - M);
            // cout << x << ' ' << i << ' ' << j << ' ' << res << endl;
        } else {
            // cout << x << ' ' << i << ' ' << sum[n - 1] - sum[i] << ' ' << endl;
            res += sum[n - 1] - sum[i] + (LL)(n - i - 1) * (x - M);
        }
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