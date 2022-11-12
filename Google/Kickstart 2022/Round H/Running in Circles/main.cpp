#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int l, n;
    cin >> l >> n;
    int curr = 0;
    LL res = 0;
    string dir = "C";
    for (int i = 0; i < n; i++) {
        int d;
        string c;
        cin >> d >> c;
        if (c == "C") {
            if (curr == 0) dir = c;
            if (d >= l - curr) {
                int t = d - (l - curr);
                res += t / l + (dir == c && l - curr != 0);
                dir = c;
            }
            curr = (curr + d % l) % l;
        } else {
            if (curr == 0) dir = c;
            if (d >= curr) {
                int t = d - curr;
                res += t / l + (dir == c && curr != 0);
                dir = c;
            }
            curr = (curr - d % l + l) % l;
        }
        // cout << i << ' ' << curr << ' ' << dir << ' ' << res << endl;
    }
    cout << res << endl;
}

int main() {
   int ts = 1;
   cin >> ts;
   for (int t = 1; t <= ts; t++) {
       cout << "Case #" << t << ": ";
       solve();
   }
   return 0;
}

