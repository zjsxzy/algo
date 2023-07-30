#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    string s;
    cin >> s;
    for (auto c: s) {
        if (c >= 'a' && c <= 'z') {
            int t = c - 'a';
            t = (t - 1 + 26) % 26;
            cout << (char)(t + 'a');
        } else if (c >= 'A' && c <= 'Z') {
            int t = c - 'A';
            t = (t + 1) % 26;
            cout << (char)(t + 'A');
        } else {
            cout << c;
        }
    }
    cout << endl;
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