#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    string A, B;
    cin >> A >> B;
    for (int i = 0; i < n; i++) {
        char c = min(A[i], B[i]), d = max(A[i], B[i]);
        A[i] = c;
        B[i] = d;
    }
    const int mod = 998244353;
    LL a = 0;
    reverse(A.begin(), A.end());
    LL m = 1;
    for (int i = 0; i < n; i++) {
        LL ai = (A[i] - '0') * m;
        ai %= mod;
        a += ai;
        a %= mod;
        m *= 10;
        m %= mod;
    }
    reverse(B.begin(), B.end());
    LL res = 0;
    m = 1;
    for (int i = 0; i < n; i++) {
        LL bi = (B[i] - '0') * m;
        bi %= mod;
        res += bi * a;
        res %= mod;
        m *= 10;
        m %= mod;
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