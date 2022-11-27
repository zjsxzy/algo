#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    for (int i = 0; i <= n - m; i++) {
        if (s.substr(i, m) == t) {
            cout << "Yes" << endl;
            return;
        }
    }
    cout << "No" << endl;
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

