#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    string s, t;
    cin >> s >> t;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        if (s[i] != t[i]) {
            cout << i + 1 << endl;
            return;
        }
    }
    cout << n + 1 << endl;
}

int main() {
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}

