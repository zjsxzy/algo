#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, k1, k2;
    cin >> n >> k1 >> k2;
    if (k1 > 60) k1 = 60;
    if (k2 > 60) k2 = 60;
    vector<LL> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    auto get = [&](int i, int k) {
        return a[i] - (a[i] & ((1ll << k) - 1));
    };
    auto calc = [&](int k) {
        LL res = 0;
        for (int i = 1, j; i <= n; i = j + 1) {
            j = i;
            LL val = get(i, k);
            while (j < n && get(j + 1, k) == val) j++;
            res += 1ll * (j - i + 1) * (j - i) / 2;
        }
        return res;
    };
    LL t1 = calc(k1), t2 = calc(k2);
    cout << t2 - t1 << endl;
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