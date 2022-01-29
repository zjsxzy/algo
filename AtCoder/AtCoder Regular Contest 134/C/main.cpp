#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int maxn = 100005;
const LL mod = 998244353;
int n, k;
LL a[maxn];
// LL fac[mod + maxk], inv[mod + maxk];

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
    cin >> n >> k;
    LL mx = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    LL res = 1;
    for (int i = 2; i <= n; i++) {
        res = (res * C(a[i] + k - 1, k - 1)) % mod;
        a[1] -= a[i];
    }
    if (a[1] < k) {
        res = 0;
    } else {
        res = (res * C(a[1] - 1, k - 1)) % mod;
    }
    cout << res << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

