#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    int x, y;
    cin >> x >> y;
    int d = y - x;
    if (d < 0) {
        cout << abs(d) << endl;
        return;
    }
    if (d % 2 == 0) cout << d / 2 << endl;
    else cout << (d + 1) / 2 + 1 << endl;
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

