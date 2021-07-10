#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const LL mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    sort(c.begin(), c.end());
    LL res = c[0];
    for (int i = 1; i < n; i++) {
        if (c[i] - i <= 0) {
            cout << 0 << endl;
            return;
        } else {
            res = res * (LL)(c[i] - i) % mod;
        }
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

