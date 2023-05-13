#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    int m = s.size();
    while (m <= 60) s += '0', m++;
    LL n, res = -1;
    cin >> n;
    bool flag = true;
    for (int i = 0; i <= 60; i++) {
        if (n >> i & 1 && s[i] == '0') {
            flag = false;
            break;
        }
        if (!(n >> i & 1) && s[i] == '1') {
            flag = false;
            break;
        }
    }
    if (flag) {
        cout << n << endl;
        return;
    }
    for (int i = 60; i >= 0; i--) {
        if (!(n >> i & 1) && s[i] == '1') break;
        if (n >> i & 1 && (s[i] == '0' || s[i] == '?')) {
            string t = s;
            for (int j = 0; j < i; j++) {
                if (t[j] == '?') t[j] = '1';
            }
            for (int j = i + 1; j <= 60; j++) {
                if (t[j] == '?' && (n >> j & 1)) t[j] = '1';
            }
            LL val = 0;
            for (int j = 0; j <= 60; j++) {
                if (t[j] == '1') val |= (1ll << j);
            }
            res = max(res, val);
        }
    }
    cout << res << endl;
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