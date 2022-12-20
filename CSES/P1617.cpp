#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL quickpow(LL x, LL n, LL mod) {
    LL res = 1;
    for (; n; n >>= 1) {
        if (n & 1) res = res * x % mod;
        x = x * x % mod;
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    cout << quickpow(2, n, 1e9 + 7) << endl;
}

int main() {
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}