#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    LL a, b, c, d, e, f, k;
    cin >> a >> b >> c >> d >> e >> f >> k;
    LL t1 = k / b * a * c, t2 = k / e * d * f;
    cout << max(t1, t2) << endl;
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