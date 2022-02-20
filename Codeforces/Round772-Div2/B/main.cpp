#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x: a) cin >> x;
    int res = 0;
    for (int i = 2; i < n; i++) {
        if (a[i - 2] < a[i - 1] && a[i - 1] > a[i]) {
            res++;
            if (i == n - 1) {
                a[i] = 1e9;
            } else {
                a[i] = max(a[i - 1], a[i + 1]);
            }
        }
    }
    cout << res << endl;
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
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

