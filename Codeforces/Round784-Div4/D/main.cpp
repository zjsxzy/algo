#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    s += "W";
    int r = 0, b = 0;
    for (auto c: s) {
        if (c == 'W') {
            if (r == 0 && b == 0) continue;
            if (r + b < 2) {
                cout << "NO" << endl;
                return;
            }
            if (r == 0 || b == 0) {
                cout << "NO" << endl;
                return;
            }
            r = 0; b = 0;
        } else if (c == 'R') {
            r++;
        } else if (c == 'B') {
            b++;
        }
    }
    cout << "YES" << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int ts;
    cin >> ts;
    while (ts--) {
        solve();
    }
    return 0;
}

