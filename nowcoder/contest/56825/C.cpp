#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    LL suma = 0, sumb = 0;
    for (auto& x: a) cin >> x, suma += x;
    for (auto& x: b) cin >> x, sumb += x;
    if (suma != sumb) {
        cout << -1 << endl;
        return;
    }
    LL res = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > b[i]) res += a[i] - b[i];
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