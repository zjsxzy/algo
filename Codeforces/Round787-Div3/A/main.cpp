#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    a -= x;
    b -= y;
    if (a < 0 && a + c >= 0) {
        c += a;
        a = 0;
    }
    if (b < 0 && b + c >= 0) {
        c += b;
        b = 0;
    }
    if (a < 0 || b < 0) cout << "NO" << endl;
    else cout << "YES" << endl;
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

