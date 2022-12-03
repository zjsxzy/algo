#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    string s;
    cin >> s;
    s += 'X';
    int res = 1, cnt = 1;
    for (int i = 1; i < (int)s.size(); i++) {
        if (s[i] != s[i - 1]) {
            res = max(res, cnt);
            cnt = 1;
        } else cnt++;
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

