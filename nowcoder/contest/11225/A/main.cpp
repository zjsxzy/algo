#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x: a) cin >> x;
    for (int i = 1; i < n; i++) {
        if (gcd(a[i], a[i - 1]) != 1) {
            cout << -1 << endl;
            return;
        }
    }
    cout << 0 << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

