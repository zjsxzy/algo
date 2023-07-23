#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, k;
    cin >> n >> k;
    const int mod = 1e9 + 7;
    vector<int> a(n);
    for (auto& x: a) cin >> x;
    LL sum = 0, min_sum = 0;
    for (int i = 0, t, x; i < k; i++) {
        cin >> t >> x;
        sum += t == 1 ? x : -x;
        min_sum = min(min_sum, sum);
    }
    LL res = 0;
    for (auto x: a) {
        if (x + min_sum >= 0) res = (res + x + sum) % mod;
        else res = (res + sum - min_sum) % mod;
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