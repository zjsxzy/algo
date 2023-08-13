#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    int x1, x2, y1, y2;
    cin >> x1 >> x2 >> y1 >> y2;
    int res = 0;
    for (int x = x1; x <= x2; x++) {
        for (int y = y1; y <= y2; y++) {
            if (a * x + b * y + c == 0) res++;
        }
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