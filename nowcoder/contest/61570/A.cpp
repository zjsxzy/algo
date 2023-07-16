#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    string s;
    cin >> s;
    for (int i = 0; i < 10; i++) {
        string t = s + (char)('0' + i);
        if (stoll(t) % 7 == 0) {
            cout << t << endl;
            return;
        }
        if (i > 0) {
            t = (char)('0' + i) + s;
            if (stoll(t) % 7 == 0) {
                cout << t << endl;
                return;
            }
        }
    }
    int n = s.size();
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 10; j++) {
            string t = s.substr(0, i) + (char)('0' + j) + s.substr(i, n - i);
            if (stoll(t) % 7 == 0) {
                cout << t << endl;
                return;
            }
        }
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