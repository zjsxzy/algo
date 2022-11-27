#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    string s;
    cin >> s;
    int res = 0;
    for (auto c: s) {
        if (c == 'v') res += 1;
        else if (c == 'w') res += 2;
    }
    cout << res << endl;
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

