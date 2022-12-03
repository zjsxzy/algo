#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<int> s(n), a(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        if (i == 0) a[i] = s[i];
        else a[i] = s[i] - s[i - 1];
    }
    for (auto x: a) cout << x << ' ';
    cout << endl;
}

int main() {
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}

