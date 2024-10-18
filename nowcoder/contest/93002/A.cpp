#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    LL x, y;
    cin >> x >> y;
    int a = 0, b = 0;
    for (int i = 0; i < 62; i++) {
        if ((x >> i & 1) != (y >> i & 1)) {
            if (x >> i & 1) a = 1;
            else b = 1;
        }
    }
    cout << a + b << endl;
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