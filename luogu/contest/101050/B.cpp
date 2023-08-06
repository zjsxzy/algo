#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    char curr = 'W';
    int res = 0;
    map<char, int> mp;
    mp['R'] = mp['B'] = mp['W'] = 1;
    for (auto c: s) {
        if (c == curr) continue;
        curr = c;
        if (c == 'R') {
            res += mp['B'] == 1;
            res += mp['W'] == 1;
            res += mp['R'] == 0;
            mp['B'] = mp['W'] = 0, mp['R'] = 1;
        } else if (c == 'B') {
            res += mp['W'] == 1;
            res += mp['B'] == 0;
            mp['W'] = 0, mp['B'] = 1;
        } else {
            res += mp['W'] == 0;
            mp['W'] = 1;
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