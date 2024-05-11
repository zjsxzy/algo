#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<int> h(n);
    for (auto& x: h) cin >> x;
    int mx = h[0];
    for (int i = 1; i < n; i++) {
        if (h[i] > mx) {
            cout << i + 1 << endl;
            return;
        }
        mx = max(mx, h[i]);
    }
    cout << -1 << endl;
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