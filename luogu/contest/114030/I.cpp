#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    LL x;
    std::cin >> n >> x;
    vector<LL> c(n), t(n), b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> c[i];
        t[i] = c[i] / x;
        b[i] = c[i] % x;
    }
    for (int i = 0; i < n; i++) {
        if (t[i] == 0) {
            std::cout << -1 << endl;
            return;
        }
    }
    sort(b.begin(), b.end());
    for (int i = 1; i < n; i++) {
        if (b[i] != b[i - 1]) {
            std::cout << -1 << endl;
            return;
        }
    }
    sort(c.begin(), c.end());
    std::cout << c[0] - x << endl;
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