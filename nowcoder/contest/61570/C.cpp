#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    LL n, m, a, b;
    cin >> n >> m >> a >> b;
    LL res = 0;
    for (int i = 0; i <= n; i++) {
        if (i * 2 > m) continue;
        LL t = b * i;
        t += min((n - i) / 2, m - i * 2) * a;
        // cout << i << ' ' << t << endl;
        res = max(res, t);
    }
    cout << res << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}