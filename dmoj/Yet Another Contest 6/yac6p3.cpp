#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    LL n, m;
    cin >> n >> m;
    vector<LL> a(4);
    cout << "? " << 1 << ' ' << 1 << endl;
    cout << flush;
    cin >> a[0];
    cout << "? " << 1 << ' ' << m << endl;
    cout << flush;
    cin >> a[1];
    cout << "? " << n << ' ' << 1 << endl;
    cout << flush;
    cin >> a[2];
    cout << "? " << n << ' ' << m << endl;
    cout << flush;
    cin >> a[3];
    auto insideX = [&](int x) {
        return x > 0 && x <= n;
    };
    auto insideY = [&](int y) {
        return y > 0 && y <= m;
    };
    LL t = a[0] + a[1] + 3 - m;
    if (t >= 0 && t % 2 == 0) {
        LL A = t / 2, B = a[0] + 2 - A;
        t = 2 * n + m - 1 - (a[2] + a[3]);
        if (t >= 0 && t % 2 == 0) {
            LL C = t / 2, D = n + m - a[3] - C;
            if (insideX(A) && insideY(B) && insideX(C) && insideY(D)) {
                cout << "! " << A << ' ' << B << ' ' << C << ' ' << D << endl;
                return;
            }
        }
    }
    t = a[0] + a[2] + 3 - n;
    assert(t > 0 && t % 2 == 0);
    LL B = t / 2, A = a[0] + 2 - B;
    t = n - 1 + 2 * m - (a[1] + a[3]);
    assert(t > 0 && t % 2 == 0);
    LL D = t / 2, C = n + m - a[3] - D;
    assert(insideX(A) && insideY(B) && insideX(C) && insideY(D));
    cout << "! " << A << ' ' << B << ' ' << C << ' ' << D << endl;
}

int main() {
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}