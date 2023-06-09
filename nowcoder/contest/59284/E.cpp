#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL calc(int h, int a, int k, int b, int m) {
    m--;
    int t = max(0, (k - h) / a) + 1;
    if (t > m) {
        return (LL)h + a * m;
    }
    m -= t;
    t = (k - b) / a + 1;
    m %= t;
    return (LL)b + a * m;
}

void solve() {
    int n, m, k, b;
    cin >> n >> m >> k >> b;
    vector<int> h(n), a(n);
    for (auto& x: h) cin >> x;
    for (auto& x: a) cin >> x;
    for (int i = 0; i < n; i++) {
        LL res = calc(h[i], a[i], k, b, m);
        cout << res << ' ';
    }
    cout << endl;
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