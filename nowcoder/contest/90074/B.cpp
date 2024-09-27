#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int mod = 1e9 + 7;

LL qpow(LL x, LL n) {
    LL res = 1;
    for (; n; n >>= 1) {
        if (n & 1) res = res * x % mod;
        x = x * x % mod;
    }
    return res;
}

void solve() {
    int n, m;
    cin >> n >> m;
    LL res = qpow(2, m);
    res = (res - 2 + mod) % mod;
    res = qpow(res, n);
    cout << res << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int ts = 1;
    cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}