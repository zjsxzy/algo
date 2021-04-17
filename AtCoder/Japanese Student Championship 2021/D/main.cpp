#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const LL mod = 1000000000 + 7;
LL n, p;
void solve() {
    cin >> n >> p;
    LL b = n - 1, a = (p - 2) % mod;
    LL res = 1;
    for (; b; b >>= 1) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
    }
    cout << res * (p - 1) % mod << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

