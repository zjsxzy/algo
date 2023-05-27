#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

bool similar(char a, char b) {
    if (a == b) return true;
    if (a == '1' && b == 'l') return true;
    if (a == 'l' && b == '1') return true;
    if (a == '0' && b == 'o') return true;
    if (a == 'o' && b == '0') return true;
    return false;
}

void solve() {
    int n;
    string s, t;
    cin >> n >> s >> t;
    for (int i = 0; i < n; i++) {
        if (!similar(s[i], t[i])) {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
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