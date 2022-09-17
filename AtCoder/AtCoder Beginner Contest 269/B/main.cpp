#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n = 10;
    vector<string> s(n);
    for (auto& x: s) cin >> x;
    auto check = [&](int a, int b, int c, int d) {
        vector<string> t(n, "..........");
        for (int i = a; i <= b; i++) {
            for (int j = c; j <= d; j++) {
                t[i][j] = '#';
            }
        }
        if (s == t) return true;
        return false;
    };
    for (int a = 1; a <= 10; a++) {
        for (int b = a; b <= 10; b++) {
            for (int c = 1; c <= 10; c++) {
                for (int d = c; d <= 10; d++) {
                    if (check(a - 1, b - 1, c - 1, d - 1)) {
                        cout << a << ' ' << b << endl;
                        cout << c << ' ' << d << endl;
                        return;
                    }
                }
            }
        }
    }
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

