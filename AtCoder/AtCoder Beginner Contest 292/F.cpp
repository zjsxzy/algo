#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int A, B;
    cin >> A >> B;
    double lo = 0, hi = 30, a = min(A, B), b = max(A, B);
    while (hi - lo >= 1e-9) {
        double mid = (lo + hi) / 2;
        if (a / cos(mid * M_PI / 180) <= b / cos((30 - mid) * M_PI / 180)) {
            lo = mid;
        } else {
            hi = mid;
        }
    }
    printf("%.9f", a / cos(lo * M_PI / 180));
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