#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<LL> a(n);
    for (auto& x: a) {
        cin >> x;
    }
    sort(a.begin(), a.end());
    if (n <= 2) {
        cout << 0 << endl;
        return;
    }
    if (n == 3) {
        cout << min(a[1] - a[0], a[2] - a[1]) << endl;
        return;
    }
    LL s1 = 0, s2 = 0;
    for (int i = 0; i < n - 1; i++) {
        s1 += abs(a[i] - a[(n - 1) / 2]);
    }
    for (int i = 1; i < n; i++) {
        s2 += abs(a[i] - a[(n - 1) / 2 + 1]);
    }
    LL res = min(s1, s2);
    int l = 1, r = n - 2;
    while (l < r) {
        LL d1 = a[r] - a[0], d2 = a[n - 1] - a[l];
        res = min(res, abs(d1 - d2));
        if (d1 < d2) l++;
        else r--;
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

