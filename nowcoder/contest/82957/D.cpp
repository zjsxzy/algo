#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x: a) cin >> x;
    vector<int> g(n);
    g[0] = a[0];
    for (int i = 1; i < n; i++) {
        g[i] = gcd(g[i - 1], a[i]);
        if (g[i] != a[i]) {
            cout << -1 << endl;
            return;
        }
    }
    for (auto x: a) cout << x << ' ';
    cout << endl;
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