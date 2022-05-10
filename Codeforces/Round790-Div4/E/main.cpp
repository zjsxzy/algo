#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n), s(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.rbegin(), a.rend());
    for (int i = 0; i < n; i++) {
        if (i == 0) s[i] = a[i];
        else s[i] = s[i - 1] + a[i];
    }
    while (q--) {
        int x;
        cin >> x;
        if (x > s[n - 1]) {
            cout << -1 << '\n';
        } else {
            auto t = lower_bound(s.begin(), s.end(), x) - s.begin();
            cout << t + 1 << '\n';
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int ts;
    cin >> ts;
    while (ts--) {
        solve();
    }
    return 0;
}

