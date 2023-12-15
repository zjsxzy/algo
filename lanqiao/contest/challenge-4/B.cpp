#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    if (a + b <= c || a + c <= b || b + c <= a) {
        cout << -1 << endl;
        return;
    }
    LL s = (a + b + c) / 2;
    cout << s * (s - a) * (s - b) * (s - c) << endl;
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