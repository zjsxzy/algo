#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x: a) cin >> x;
    int res = 0;
    for (int i = n - 2; i >= 0; i--) {
        int x = a[i];
        while (x && x >= a[i + 1]) {
            x /= 2;
            res++;
        }
        if (x >= a[i + 1]) {
            cout << -1 << endl;
            return;
        }
        a[i] = x;
    }
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

