#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int h, w;
    cin >> h >> w;
    int res = 0;
    for (int i = 0; i < h; i++) {
        string s;
        cin >> s;
        for (auto c: s) {
            if (c == '#') res++;
        }
    }
    cout << res << endl;
}

int main() {
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}

