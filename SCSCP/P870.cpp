#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int mod = 1e9 + 7;

LL quickpow(LL a, LL x) { // a^x%mod
    LL res = 1;
    for (; x; x >>= 1) {
        if (x & 1) res = res * a % mod;
        a = a * a % mod;
    }
    return res;
}

LL C(int n, int m) { // C(n, m) = n!/((n-m)!*m!)%mod
    if (n < m) return 0;
    // return fac[n] * inv[n - m] % mod * inv[m] % mod;
    LL num = 1;
    for (int i = n - m + 1; i <= n; i++) {
        num = num * i % mod;
    }
    LL den = 1;
    for (int i = 1; i <= m; i++) {
        den = den * i % mod;
    }
    return num * quickpow(den, mod - 2) % mod;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    if (k < n - 1) {
        cout << 0 << endl; 
        return;
    }
    if (m == 0) {
        int P = (n * (n - 1)) / 2;
        cout << C(P, k) << endl;
    } else if (m == 1) {
        int P = (n - 1) * (n - 2) / 2;
        cout << C(n - 1, 2) * C(P, k - 2) % mod << endl;
    } else {
        cout << -1 << endl;
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