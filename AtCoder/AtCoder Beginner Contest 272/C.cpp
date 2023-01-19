#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    set<int> odd, even;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] & 1) odd.insert(a[i]);
        else even.insert(a[i]);
    }
    int res = -1;
    if (!odd.empty()) {
        auto x = *odd.rbegin();
        odd.erase(x);
        if (!odd.empty()) res = max(res, x + *odd.rbegin());
    }
    if (!even.empty()) {
        auto x = *even.rbegin();
        even.erase(x);
        if (!even.empty()) res = max(res, x + *even.rbegin());
    }
    cout << res << endl;
}

int main() {
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}