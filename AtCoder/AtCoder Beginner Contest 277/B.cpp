#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    auto check = [&](string x) {
        string first = "HDCS", second = "A23456789TJQK";
        bool f1 = false, f2 = false;
        for (auto c: first) f1 |= (c == x[0]);
        for (auto c: second) f2 |= (c == x[1]);
        return f1 && f2;
    };
    for (int i = 0; i < n; i++) {
        if (!check(s[i])) {
            cout << "No" << endl;
            return;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (s[i] == s[j]) {
                cout << "No" << endl;
                return;
            }
        }
    }
    cout << "Yes" << endl;
}

int main() {
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}