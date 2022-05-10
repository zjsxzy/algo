#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int mn = INT_MAX;
    for (auto& x: a) {
        cin >> x;
        mn = min(mn, x);
    }
    int res = 0;
    for (int i = 0; i < n; i++) res += a[i] - mn;
    cout << res << endl;
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

