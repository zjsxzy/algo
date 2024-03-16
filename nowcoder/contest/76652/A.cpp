#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    LL n;
    cin >> n;
    if (n & 1) {
        cout << n * (n + 1) / 2 << endl;
    } else {
        LL res = n / 2;
        LL t = n + 1;
        for (int i = 2; i <= n; i++) {
            if (i == n / 2) continue;
            LL g = gcd(i, t);
            if (g > 1) {
                res *= g;
                t /= g;
            }
            if (t == 1) break;
        }
        cout << res << endl;
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