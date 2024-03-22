#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    int mn = INT_MAX, mx = 0;
    for (auto& x: a) {
        cin >> x;
        mn = min(mn, x);
        mx = max(mx, x);
    }
    if (mn == 1 && mx == m) cout << "No" << endl;
    else cout << "Yes" << endl;
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