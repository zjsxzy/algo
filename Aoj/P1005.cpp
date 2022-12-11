#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    LL a, b;
    while (cin >> a >> b) {
        cout << gcd(a, b) << ' ' << lcm(a, b) << endl;
    }
}

int main() {
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}