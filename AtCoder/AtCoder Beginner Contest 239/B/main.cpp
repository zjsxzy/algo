#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    LL x, res;
    cin >> x;
    if (x >= 0) {
        res = x / 10;
    } else {
        x = abs(x);
        if (x % 10 == 0) res = -x / 10;
        else res = -x / 10 - 1;
    }
    cout << res << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

