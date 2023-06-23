#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    LL a, b, k, r, c;
    cin >> a >> b >> k >> r >> c;
    LL res = k * (r - c) * (b - a);
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