#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    int a, b, c, d, e, f, x;
    cin >> a >> b >> c >> d >> e >> f >> x;
    int l1 = 0, l2 = 0;
    int n = x;
    while (n > 0) {
        int t = min(n, a);
        l1 += t * b;
        n -= t;
        n -= c;
    }
    n = x;
    while (n > 0) {
        int t = min(n, d);
        l2 += t * e;
        n -= t;
        n -= f;
    }
    if (l1 > l2) cout << "Takahashi" << endl;
    else if (l1 < l2) cout << "Aoki" << endl;
    else cout << "Draw" << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

