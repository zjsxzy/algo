#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> a(n);
    for (auto& e: a) cin >> e;
    vector<pair<int, int>> s;
    for (int i = 0; i < k; i++) {
        vector<int> v;
        for (int j = i; j < n; j += k) {
            v.push_back(a[j]);
        }
        sort(v.begin(), v.end());
        s.push_back({v.back(), v.size()});
        LL sum = 0;
        for (auto e: v) {
            x -= (v.back() - e);
            if (x < 0) {
                cout << -1 << endl;
                return;
            }
        }
    }
    int res = 0;
    for (auto p: s) {
        res = max(res, p.first + x / p.second);
    }
    cout << res << endl;
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