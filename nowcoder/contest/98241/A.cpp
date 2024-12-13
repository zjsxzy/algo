#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    int res = 0;
    while (n) {
        if (n >= a) {
            res++;
            n -= a;
            continue;
        }
        if (n >= b) {
            res++;
            n -= b;
            continue;
        }
        if (n >= c) {
            res++;
            n -= c;
            continue;
        }
        break;
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