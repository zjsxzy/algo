#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<string> s(n), t(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i] >> t[i];
    }
    for (int i = 0; i < n; i++) {
        bool f1 = true, f2 = true;
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (s[i] == s[j]) f1 = false;
            if (s[i] == t[j]) f1 = false;
            if (t[i] == s[j]) f2 = false;
            if (t[i] == t[j]) f2 = false;
        }
        if (!f1 && !f2) {
            cout << "No" << endl;
            return;
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