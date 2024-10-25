#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    LL x;
    cin >> x;
    if (x == 2) {
        cout << 1 << endl;
        return;
    }
    for (int i = 60; i >= 0; i--) {
        if (x >> i & 1) {
            if (x == (1ll << i)) {
                cout << x << endl;
            } else {
                cout << (1ll << (i + 1)) << endl;
            }
            return;
        }
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