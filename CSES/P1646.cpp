#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<LL> a(n), sum(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum[i + 1] = sum[i] + a[i];
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << sum[r] - sum[l - 1] << endl;
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