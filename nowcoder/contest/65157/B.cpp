#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    string s;
    cin >> s;
    int a = 0, b = 0, res = 0;
    auto f = [&](int x) {
        if (x == 0) return 2;
        if (x < 10) return 1;
        return x % 10 == 0 ? 1 : 0;
    };
    for (auto c: s) {
        if (c == 'a') a++;
        else b++;
        res += f(a) + f(b);
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