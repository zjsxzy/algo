#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    int res = 0;
    auto f = [&](int x) {
        int a = x;
        if (a >= 500) a -= a / 10;
        int b = x;
        if (b >= 1000) b -= 150;
        int c = x;
        if (c == 1111) c = 0;
        else c -= c / 20;
        return min(min(a, b), c);
    };
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        res += f(x);
        // cout << f(x) << endl;
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