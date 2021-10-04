#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    LL b = 1;
    int i = 0;
    if (n == 1) {
        cout << 1 << endl;
        return;
    }
    while (n >= (1 << i)) {
        i++;
    }
    i--;
    int res = max((1 << i) >> 1, n - (1 << i) + 1);
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

