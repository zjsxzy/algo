#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, a, b, res = 0;
    cin >> n >> a >> b;
    for (int i = 0; i <= n / a; i++) {
        for (int j = 0; i * a + j * b <= n; j++) {
            res = max(res, i + j);
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