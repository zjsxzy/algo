#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    for (int i = 1; i <= n; i++) {
        for (int d = 1; i + d - 1 <= n; d <<= 1) {
            v.emplace_back(i, i + d - 1);
        }
    }
    cout << v.size() << endl;
    for (auto e: v) {
        cout << e.first << ' ' << e.second << endl;
        fflush(stdout);
    }
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        int d = 1;
        for (; l + d - 1 <= r; d <<= 1);
        d >>= 1;
        int x = lower_bound(v.begin(), v.end(), make_pair(l, l + d - 1)) - v.begin() + 1;
        int y = lower_bound(v.begin(), v.end(), make_pair(r - d + 1, r)) - v.begin() + 1;
        cout << x << ' ' << y << endl;
        fflush(stdout);
    }
}

int main() {
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}