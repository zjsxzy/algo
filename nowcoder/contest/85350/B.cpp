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

LL sum(LL a, LL x) {
    if (x == 1) return a % mod;
    else if(x & 1) return ( sum(a, x / 2) % mod + ( (sum(a, x / 2) % mod) * (qpow(a, x / 2) % mod) ) + qpow(a, x) % mod ) % mod;
    else return ( sum(a, x / 2) % mod + ( (sum(a, x / 2) % mod) * (qpow(a, x / 2) % mod) ) ) % mod;
}

void solve() {
    int w, d;
    cin >> w >> d;
    LL res = 1;
    for (int i = 0; i < w; i++) {
        LL p, a;
        cin >> p >> a;
        LL t = sum(qpow(p, d), a) + 1;
        t %= mod;
        // cout << t << endl;
        res *= t;
        res %= mod;
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