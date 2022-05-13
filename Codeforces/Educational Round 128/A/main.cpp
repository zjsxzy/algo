#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    int res;
    if (r1 < l2 || r2 < l1) {
        res = l1 + l2;
    } else {
        res = max(l1, l2);
    }
    cout << res << endl;
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

