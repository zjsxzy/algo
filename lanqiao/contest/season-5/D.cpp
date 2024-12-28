#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    auto f = [&](int x) {
        int q = sqrt(x);
        return q * q == x;
    };
    int res = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (!(x & 1) || f(x)) res++;
    }
    cout << res << '\n';
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