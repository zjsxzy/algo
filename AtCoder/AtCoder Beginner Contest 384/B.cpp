#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, r;
    cin >> n >> r;
    for (int i = 0; i < n; i++) {
        int d, a;
        cin >> d >> a;
        if (r >= 1600 && r < 2800 && d == 1) {
            r += a;
        } else if (r >= 1200 && r < 2400 && d == 2) {
            r += a;
        }
    }
    cout << r << '\n';
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