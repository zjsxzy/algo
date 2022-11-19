#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto& x: a) cin >> x;
    if (k < n) {
        for (int i = k; i < n; i++) cout << a[i] << ' ';
    }
    for (int i = 0; i < min(n, k); i++) cout << '0' << ' ';
    cout << endl;
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

