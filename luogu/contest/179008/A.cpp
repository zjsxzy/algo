#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    LL n, m;
    // cin >> n >> m;
    scanf("%ld%ld", &n, &m);
    // cout << n << ' ' << m << endl;
    int k;
    // cin >> k;
    scanf("%d", &k);
    // cout << k << endl;
    int res = 0;
    while (k--) {
        // int x, y;
        LL x, y;
        // cin >> x >> y;
        scanf("%ld%ld", &x, &y);
        // cout << x << ' ' << y << endl;
        if (y >= x) res++;
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