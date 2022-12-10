#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    string s;
    cin >> s;
    if (s.size() != 8) {
        cout << "No" << endl;
        return;
    }
    if (s[0] < 'A' || s[0] > 'Z') {
        cout << "No" << endl;
        return;
    }
    if (s[7] < 'A' || s[7] > 'Z') {
        cout << "No" << endl;
        return;
    }
    int t = stoi(s.substr(1, 6));
    if (t >= 100000 && t < 1000000) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}

int main() {
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}