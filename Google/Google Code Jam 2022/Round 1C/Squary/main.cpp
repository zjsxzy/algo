#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    int n, k;
    cin >> n >> k;
    LL sum = 0, sumsq = 0;
    for (int i = 0; i < n; i++) {
        LL x;
        cin >> x;
        sum += x;
        sumsq += x * x;
    }
    if (sum == 0) {
        if (sumsq != 0) {
            cout << "IMPOSSIBLE" << endl;
        } else {
            cout << 0 << endl;
        }
    } else {
        if ((sumsq - sum * sum) % (2 * sum) == 0) {
            cout << (sumsq - sum * sum) / (2 * sum) << endl;
        } else {
            cout << "IMPOSSIBLE" << endl;
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int ts;
    cin >> ts;
    for (int i = 1; i <= ts; i++) {
        printf("Case #%d: ", i);
        solve();
    }
    return 0;
}

