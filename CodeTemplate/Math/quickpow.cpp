LL qpow(LL x, LL n) {
    LL res = 1;
    for (; n; n >>= 1) {
        if (n & 1) res = res * x % mod;
        x = x * x % mod;
    }
    return res;
}

// 等比数列求和
LL sum(LL a, LL x) {
    if (x == 1) return a % mod;
    else if(x & 1) return ( sum(a, x / 2) % mod + ( (sum(a, x / 2) % mod) * (qpow(a, x / 2) % mod) ) + qpow(a, x) % mod ) % mod;
    else return ( sum(a, x / 2) % mod + ( (sum(a, x / 2) % mod) * (qpow(a, x / 2) % mod) ) ) % mod;
}
