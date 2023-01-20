#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<string> s(n + 1);
    s[1] = "1";
    for (int i = 2; i <= n; i++) {
        s[i] = s[i - 1] + ' ' + to_string(i) + ' ' + s[i - 1];
    }
    cout << s[n] << endl;
}

int main() {
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}