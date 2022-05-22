#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool f = false;
    for (auto c: s) {
        if (c >= 'A' && c <= 'Z') {
            f = true;
            break;
        }
    }
    if (!f) s += 'A';

    f = false;
    for (auto c: s) {
        if (c >= 'a' && c <= 'z') {
            f = true;
            break;
        }
    }
    if (!f) s += 'a';

    f = false;
    for (auto c: s) {
        if (c >= '0' && c <= '9') {
            f = true;
            break;
        }
    }
    if (!f) s += '1';

    f = false;
    for (auto c: s) {
        if (c == '#' || c == '@' || c == '*' || c == '&') {
            f = true;
            break;
        }
    }
    if (!f) s += '@';

    while (s.size() < 7) {
        s += '1';
    }
    cout << s << endl;
}

int main() {
   int ts = 1;
   cin >> ts;
   for (int t = 1; t <= ts; t++) {
       cout << "Case #" << t << ": ";
       solve();
   }
   return 0;
}

