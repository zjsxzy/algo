#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<int> l(n), r(n);
    for (int i = 0; i < n; i++) cin >> l[i] >> r[i];
    vector<int> a(n), f(n);
    a[0] = l[0];
    f[0] = 1;
    for (int i = 1; i < n; i++) {
        int id = -1, val = -1;
        for (int j = 0; j < i; j++) {
            if (a[j] < r[i] && (f[j] > val || (f[j] == val && a[j] < a[id]))) {
                id = j;
                val = f[j];
            }
        }
        // cout << i << ' ' << val << ' ' << id << endl;
        if (val == -1) {
            a[i] = l[i];
            f[i] = 1;
        } else {
            a[i] = max(l[i], a[id] + 1);
            f[i] = f[id] + 1;
        }
    }
    // for (auto x: a) cout << x << ' ';
    // cout << endl;
    int res = 1;
    for (int i = 0; i < n; i++) res = max(res, f[i]);
    cout << res << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}