#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, l;
    cin >> n >> l;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int i = 0, p = 1;
    while (p + a[i] - 1 < l) {
        p += a[i] + 1;
        i++;
    }
    if (p == l - 1 && a[i] == 2) i++;
    for (; i < n; i++) {
        if (a[i] == 2) {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}

