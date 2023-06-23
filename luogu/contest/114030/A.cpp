#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    double c, i, g, m, x;
    cin >> c >> i >> g >> m >> x;
    double res = c + i + g + x - m;
    printf("%.2f\n", res);
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