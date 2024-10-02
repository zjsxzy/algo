#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    LL x1 = 1e18;
    cout << "? " << x1 << endl;
    LL r1;
    cin >> r1;
    LL x2 = x1 - r1 - 1;
    cout << "? " << x2 << endl;
    LL r2;
    cin >> r2;
    cout << "! " << (x1 - x2) - (r1 - r2) << endl;
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