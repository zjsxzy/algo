#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector g(n + 1, vector<int>(m + 1, 1));
    while (k--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int i = x1; i <= x2; i++) {
            for (int j = y1; j <= y2; j++) {
                g[i][j] ^= 1;
            }
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            res += g[i][j];
        }
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