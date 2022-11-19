#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

bool valid(int a, int b, int c, int d) {
    int h = a * 10 + b;
    int m = c * 10 + d;
    return (h >= 0 && h < 24 && m >= 0 && m < 60);
}

bool confuse(int h, int m) {
    int a = h / 10, b = h % 10;
    int c = m / 10, d = m % 10;
    return valid(a, b, c, d) && valid(a, c, b, d);
}

void solve() {
    int h, m;
    cin >> h >> m;
    while (!confuse(h, m)) {
        m++;
        if (m == 60) {
            h++;
            if (h == 24) h = 0;
            m = 0;
        }
    }
    cout << h << ' ' << m << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}

