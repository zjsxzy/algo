#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    for (int i = 1; i < n; i++) {
        int l = 0;
        while (l + i < n && s[l] != s[l + i]) {
            l++;
        }
        cout << l << endl;
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