#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<LL> h(n);
    LL res = 0, mx = 0;
    for (auto& x: h) {
        cin >> x;
        mx = max(mx, x);
    }
    for (int i = 1; i < n; i++) {
        res += abs(h[i] - h[i - 1]);
    }
    vector<LL> v;
    LL sum = 0;
    for (int i = 1, j = 0; i < n; i++) {
        sum += abs(h[i] - h[i - 1]);
        if (h[i] >= h[j]) {
            v.push_back(sum - abs(h[i] - h[j]));
            j = i;
            sum = 0;
        }
    }
    if (h.back() != mx) {
        sum = 0;
        for (int i = n - 2, j = n - 1; i >= 0; i--) {
            sum += abs(h[i] - h[i + 1]);
            if (h[i] >= h[j]) {
                v.push_back(sum - abs(h[i] - h[j]));
                j = i;
                sum = 0;
            }
            if (h[i] == mx) break;
        }
    }
    sort(v.rbegin(), v.rend());
    for (int i = 0; i < m && i < (int)v.size(); i++) {
        res -= v[i];
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