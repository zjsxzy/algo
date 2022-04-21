#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    int r;
    cin >> r;
    cout << "Division ";
    if (r >= 1900) cout << 1 << endl;
    else if (r >= 1600) cout << 2 << endl;
    else if (r >= 1400) cout << 3 << endl;
    else cout << 4 << endl;
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

