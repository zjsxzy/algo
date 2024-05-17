#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    LL y;
    cin >> y;
    vector<LL> f(18);
    f[0] = 1;
    for (int i = 1; i < 18; i++) {
        f[i] = f[i - 1] * 10;
    }
    int res = 0;
    for (int a = 1; a < 10; a++) {
        for (int b = 0; b < 10; b++) {
            for (int t = 0; t < 18; t++) {
                LL r = y - (LL)a * f[t] - b;
                if (r < 0) continue;
                if (t == 0) {
                    if (r == 0) {
                        res++;
                    }
                } else {
                    if (r % 11 != 0) continue;
                    LL x = r / 11;
                    if (x < f[t]) {
                        res++;
                    }
                }
            }
        }
    }
    std::cout << res << endl;
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