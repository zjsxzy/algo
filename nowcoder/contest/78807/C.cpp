#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    int x = n / 2 + 1, y = m / 2 + 1;
    int res = 0;
    while (k--) {
        int i, j;
        cin >> i >> j;
        if (abs(x - i) <= n / 2 && abs(y - j) <= m / 2) {
            if (n < m) {
                if (abs(y - j) + abs(x - i) <= m / 2) res++;
            } else {
                if (abs(x - i) + abs(y - j) <= n / 2) res++;
            }
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