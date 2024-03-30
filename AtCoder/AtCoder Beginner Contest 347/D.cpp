#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int count(LL x) {
    int res = 0;
    for (int i = 0; i < 61; i++) {
        if (x >> i & 1) res++;
    }
    return res;
}

void solve() {
    int a, b;
    LL C;
    cin >> a >> b >> C;
    int c = count(C);
    if (c > a + b) {
        cout << -1 << endl;
        return;
    }
    for (int i = 0; i <= min(a, b); i++) {
        int na = a - i, nb = b - i;
        if (na + nb == c) {
            LL A = 0, B = 0;
            for (int j = 0; j < 61; j++) {
                if (C >> j & 1) {
                    if (na) {
                        na--;
                        A |= (1LL << j);
                    } else {
                        nb--;
                        B |= (1LL << j);
                    }
                }
            }
            int cnt = i;
            for (int j = 0; j < 61; j++) {
                if (cnt > 0 && !(C >> j & 1) && !(A >> j & 1) && !(B >> j & 1)) {
                    cnt--;
                    A |= (1LL << j);
                    B |= (1LL << j);
                }
            }
            if (A <= (1LL << 60) || (B <= 1LL << 60)) {
                cout << A << ' ' << B << endl;
                // cout << count(A) << ' ' << count(B) << ' ' << (A ^ B) << endl;
                return;
            }
        }
    }
    cout << -1 << endl;
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