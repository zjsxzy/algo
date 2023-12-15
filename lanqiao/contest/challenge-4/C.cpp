#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    LL n, q;
    cin >> n >> q;
    while (q--) {
        LL x;
        cin >> x;
        x++;
        LL u = x / 3 + 1, v = x % 3 - 1;
        cout << u << ' ' << u + v << endl;
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