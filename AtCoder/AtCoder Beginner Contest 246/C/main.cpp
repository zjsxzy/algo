#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        int t = a[i] / x;
        int use = min(t, k);
        k -= use;
        a[i] -= use * x;
    }
    sort(a.rbegin(), a.rend());
    for (int i = 0; i < n; i++) {
        if (k > 0) {
            a[i] = 0;
            k--;
        } else {
            break;
        }
    }
    LL res = 0;
    for (int i = 0; i < n; i++) {
        res += a[i];
    }
    cout << res << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

