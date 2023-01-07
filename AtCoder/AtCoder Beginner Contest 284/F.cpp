#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int M = 1e9 + 7;
const int B = 233;

LL quickpow(LL x, LL n, LL mod) {
    LL res = 1;
    for (; n; n >>= 1) {
        if (n & 1) res = res * x % mod;
        x = x * x % mod;
    }
    return res;
}

vector<LL> get_hash(string s) {
    int n = s.size();
    vector<LL> sum(n + 1);
    for (int i = 0; i < n; ++i) {
        sum[i + 1] = (LL)(sum[i] * B + s[i]) % M;
    }
    return sum;
}

void solve() {
    int n;
    string s;
    cin >> n >> s;
    string t = s;
    reverse(t.begin(), t.end());
    vector<LL> ss = get_hash(s);
    vector<LL> st = get_hash(t);
    for (int i = 1; i <= n; i++) {
        LL sl = ss[i], sr = (ss[2 * n] - ss[2 * n - (n - i)] * quickpow(B, n - i, M) % M + M) % M;
        LL tl = (st[n - i + i] - st[n - i] * quickpow(B, i, M) % M + M) % M;
        LL tr = (st[n - i + n] - st[n] * quickpow(B, n - i, M) % M + M) % M;
        if (sl == tl && sr == tr) {
            cout << t.substr(n - i, n) << endl;
            cout << i << endl;
            return;
        }
    }
    cout << -1 << endl;
}

int main() {
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}