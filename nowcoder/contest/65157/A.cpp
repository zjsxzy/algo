#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    double a, b;
    cin >> a >> b;
    double res = M_PI * (a + b) * (a + b);
    cout << fixed << setprecision(10) << res << endl;
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