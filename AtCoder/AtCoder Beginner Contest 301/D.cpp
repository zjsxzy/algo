#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    LL n, m = 0;
    cin >> n;
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == '1') m |= (1ll << i);
    }
    if (m > n) {
        cout << -1 << endl;
    } else {
        for (int i = (int)s.size() - 1; i >= 0; i--) {
            if (s[i] == '?' && (m | (1ll << i)) <= n) m |= (1ll << i);
        }
        cout << m << endl;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}