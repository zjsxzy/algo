#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    LL sum = (LL)n * (n + 1) / 2;
    if (sum & 1) {
        cout << "NO" << endl;
        return;
    }
    LL ans = sum / 2;
    vector<int> a, b;
    for (int i = n; i >= 1; i--) {
        if (i <= ans) {
            a.push_back(i);
            ans -= i;
        } else {
            b.push_back(i);
        }
    }
    cout << "YES" << endl;
    cout << (int)a.size() << endl;
    for (auto x: a) cout << x << ' ';
    cout << endl;
    cout << (int)b.size() << endl;
    for (auto x: b) cout << x << ' ';
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

