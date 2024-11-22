#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a * b < c * d) cout << "lz" << endl;
    else cout << "gzy" << endl;
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