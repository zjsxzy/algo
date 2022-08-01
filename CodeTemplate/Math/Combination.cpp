void init(int n) {
    memset(comb, 0, sizeof(comb));
    for (int i = 0; i <= n; i++) {
        comb[i][0] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
        }
    }
}

void factorial(int n) {
    fac[0] = 1;
    for (int i = 1; i <= n; i++) {
        fac[i] = fac[i - 1] * i;
    }
}

mint C(int n, int m) { // C(n, m) = n!/((n-m)!*m!)%mod
    if (n < m) return 0;
    if (m == 0) return 1;
    return fac[n] / fac[n - m] / fac[m];
}

// inverse of combination
LL quickpow(LL a, LL x) { // a^x%mod
    LL res = 1;
    for (; x; x >>= 1) {
        if (x & 1) res = res * a % mod;
        a = a * a % mod;
    }
    return res;
}

/*
void factorial(int n) {
    fac[0] = inv[0] = 1;
    for (int i = 1; i <= n; i++) {
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = quickpow(fac[i], mod - 2);
    }
}
*/

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
