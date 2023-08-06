#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    LL n;
    cin >> n;
    pair<LL, LL> res = {1, 1};
    LL mn = n, fact = 2;
    for (LL x = 3; x <= 20; x++) {
        fact *= x;
        LL d = max(1ll, n / (fact - 1) - 1);
        for (LL y = d; y <= d + 3; y++) {
            if (y == 2) continue;
            if (abs((fact - 1) * y - n) < mn) {
                mn = abs((fact - 1) * y - n);
                res = {x, y};
            }
        }
    }
    cout << res.first << ' ' << res.second << endl;
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