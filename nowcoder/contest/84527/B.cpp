#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    LL n;
    cin >> n;
    int mod = 1e9 + 7;
    if (n % 2 == 0) {
        LL a = (2 + n) * (n / 2) / 2;
        LL b = (3 + n - 1) * ((n - 1) / 2) / 2;
        // cout << a << ' ' << b << endl;
        cout << (a / 2 + b) % mod << endl;
    } else {
        LL a = (2 + n - 1) * ((n - 1) / 2) / 2;
        LL b = (3 + n) * (n / 2) / 2;
        // cout << a << ' ' << b << endl;
        cout << (a / 2 + b) % mod << endl;
    }
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