#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    int C = 1e6, M = 1e6, Y = 1e6, K = 1e6;
    for (int i = 0; i < 3; i++) {
        int c, m, y, k;
        cin >> c >> m >> y >> k;
        C = min(C, c);
        M = min(M, m);
        Y = min(Y, y);
        K = min(K, k);
    }
    if (C + M + Y + K < 1e6) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        int res = 1e6;
        res -= C;
        cout << C;

        int t = min(res, M);
        cout << " " << t;
        res -= t;

        t = min(res, Y);
        cout << " " << t;
        res -= t;

        t = min(res, K);
        cout << " " << t << endl;
    }
}

int main() {
    int ts;
    cin >> ts;
    for (int cs = 1; cs <= ts; cs++) {
        printf("Case #%d: ", cs);
        solve();
    }
    return 0;
}

