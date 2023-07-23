#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    LL n;
    cin >> n;
    if (n % 3 == 0) cout << n / 3 - 1 << endl;
    else cout << n / 3 * 2 << endl;
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