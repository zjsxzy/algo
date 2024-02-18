#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    LL n;
    int k;
    cin >> n >> k;
    vector<LL> a(k);
    for (auto& x: a) cin >> x;
    LL res = 0;
    for (int s = 1; s < (1 << k); s++) {
        LL prod = 1;
        for (int i = 0; i < k; i++) {
            if (s >> i & 1) {
                if (prod > n / a[i]) {
                    prod = n + 1;
                    break;
                } else {
                    prod *= a[i];
                }
            }
        }
        int b = __builtin_popcount(s);
        if (b & 1) res += n / prod;
        else res -= n / prod;
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