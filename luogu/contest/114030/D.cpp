#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int x, h;
    cin >> x >> h;
    if (x < 10) {
        cout << "Drizzle" << endl;
    } else if (x >= 10 && x < 25) {
        cout << "Moderate Rain" << endl;
    } else if (x >= 25 && x < 50) {
        cout << "Heavy Rain" << endl;
    } else {
        cout << "Torrential Rain" << endl;
    }
    if (h == 1) {
        if (x >= 20) cout << "YES" << endl;
        else cout << "NO" << endl;
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