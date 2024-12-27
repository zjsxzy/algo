#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int x, y;
    cin >> x >> y;
    if (y == 0) {
        cout << 0 << '\n';
        return;
    }
    int d = y / (x + 1);
    if ((d - 1) * (x + 1) + 1 >= y) {
        cout << 2 * d - 1 << '\n';
    } else if (d * (x + 1) >= y) {
        cout << 2 * d << '\n'; 
    } else if (d * (x + 1) + 1 >= y) {
        cout << 2 * d + 1 << '\n';
    } else if ((d + 1) * (x + 1) >= y) {
        cout << 2 * d + 2 << '\n';
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int ts = 1;
    cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}