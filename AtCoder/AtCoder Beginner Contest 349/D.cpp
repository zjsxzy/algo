#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    LL l, r;
    cin >> l >> r;
    vector<pair<LL, LL>> ans;
    LL p = l;
    while (p < r) {
        for (int i = 60; i >= 0; i--) {
            if (p % (1LL << i) == 0 && p + (1LL << i) <= r) {
                ans.push_back({p, p + (1LL << i)});
                p += 1LL << i;
                break;
            }
        }
    }
    cout << ans.size() << endl;
    for (auto [l, r]: ans) {
        cout << l << ' ' << r << endl;
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