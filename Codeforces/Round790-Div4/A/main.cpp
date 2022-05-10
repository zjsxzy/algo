#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    string s;
    cin >> s;
    int a = 0, b = 0;
    for (int i = 0; i < 3; i++) {
        a += s[i] - '0';
        b += s[5 - i] - '0';
    }
    if (a == b) cout << "YES" << endl;
    else cout << "NO" << endl;
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

