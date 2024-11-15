#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, k, m = 60;
    cin >> n >> k;
    vector<LL> a(n);
    for (auto& x: a) cin >> x;
    const int mod = 1e9 + 7;
    LL t = 1, res = 0;
    for (int i = 0; i < m; i++) {
        vector<int> cnt(k, 0);
        for (int j = 0; j < n; j++) {
            cnt[a[j] % k]++;
            a[j] /= k;
        }
        for (int a = 0; a < k; a++) {
            res += (LL)cnt[a] * (cnt[a]- 1) / 2 % mod * ((a + a) % k) % mod * t;
            res %= mod;
            for (int b = a + 1; b < k; b++) {
                res += (LL)cnt[a] * cnt[b] % mod * ((a + b) % k) % mod * t % mod;
                res %= mod;
            }
        }
        t *= k;
        t %= mod;
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