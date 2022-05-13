#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    LL a, b;
    cin >> a >> b;
    LL g = gcd(a, b);
    for (LL i = 2; i * a <= (LL)1e18; i++) {
        LL c = i * a;
        if (gcd(a, b) == gcd(b, c)) {
            cout << c << endl;
            return;
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int ts;
    cin >> ts;
    while (ts--) {
        solve();
    }
    return 0;
}

