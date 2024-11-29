#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 1e7 + 5;
const int mod = 1e9 + 7;
LL fac[maxn], inv[maxn];

LL quickpow(LL a, LL x) { // a^x%mod
    LL res = 1;
    for (; x; x >>= 1) {
        if (x & 1) res = res * a % mod;
        a = a * a % mod;
    }
    return res;
}

void factorial(int n) {
    fac[0] = inv[0] = 1;
    for (int i = 1; i <= n; i++) {
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = quickpow(fac[i], mod - 2);
    }
}

LL C(int n, int m) { // C(n, m) = n!/((n-m)!*m!)%mod
    if (n < m) return 0;
    return fac[n] * inv[n - m] % mod * inv[m] % mod;
}

void solve() {
    int n, k;
    cin >> n >> k;
    if (n & 1 || k < 2) {
        cout << 0 << endl;
        return;
    }
    cout << (C(n, k) - C(n / 2, k) * quickpow(2, k) % mod + mod) % mod << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    factorial(1e7);
    int ts = 1;
    cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}