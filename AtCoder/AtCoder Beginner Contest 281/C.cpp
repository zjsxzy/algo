#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    LL T;
    cin >> n >> T;
    vector<LL> a(n), s(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i == 0) s[i] = a[i];
        else s[i] = s[i - 1] + a[i];
    }
    T %= s[n - 1];
    for (int i = 0; i < n; i++) {
        if (s[i] > T) {
            if (i == 0) cout << 1 << ' ' << T << endl;
            else cout << i + 1 << ' ' << T - s[i - 1] << endl;
            return;
        }
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