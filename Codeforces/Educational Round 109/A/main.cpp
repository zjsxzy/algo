#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define MP make_pair
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    int x;
    cin >> x;
    int y = 100 - x;
    if (x == 0 || y == 0) {
        cout << 1 << endl;
        return;
    }
    int d = gcd(x, y);
    x /= d;
    y /= d;
    cout << x + y << endl;
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

