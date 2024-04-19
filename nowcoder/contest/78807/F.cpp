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
                t += zero[j];
                t %= mod;
            } else {
                t += one[j];
                t += mod;
            }
        }
        for (int j = 0; j < 32; j++) {
            if (x >> j & 1) {
                one[j] += (1ll << j) * (i + 1);
                one[j] %= mod;
            } else {
                zero[j] += (1ll << j) * (i + 1);
                zero[j] %= mod;
            }
        }
        res += t * (n - i + 1) % mod;
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