#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int mod = 1e9 + 7;
void solve() {
    LL n;
    cin >> n;
    if (n == 1) {
        cout << 1 << endl;
        return;
    }
    vector<LL> sum(65);
    for (int i = 2; i <= 60; i++) {
        sum[i] = sum[i - 1] + (1ll << (i - 1)) - 1;
        sum[i] %= mod;
    }
    LL res = n % mod;
    for (int i = 60; i >= 1; i--) {
        if (n >> i & 1) {
            res += sum[i];
            res %= mod;
            n -= (1ll << i) - 1;
            while (n) {
                res += n / 2;
                res %= mod;
                n /= 2;
            }
            cout << res << endl;
            return;
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int ts = 1;
    cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}