#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<LL> one(32), zero(32);
    const int mod = 1e9 + 7;
    LL res = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        LL t = 0;
        for (int j = 0; j < 32; j++) {
            if (x >> j & 1) {
                res += zero[j] * (n - i) % mod * (1ll << j) % mod;
                res %= mod;
            } else {
                res += one[j] * (n - i) % mod * (1ll << j) % mod;
                res %= mod;
            }
        }
        for (int j = 0; j < 32; j++) {
            if (x >> j & 1) {
                one[j] += i + 1;
            } else {
                zero[j] += i + 1;
            }
        }
    }
    cout << (res * 2) % mod << endl;
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