#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    LL sum = 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    LL res = INT_MAX;
    for (int s = 1; s < (1 << n); s++) {
        LL sub = 0;
        for (int i = 0; i < n; i++) {
            if (s >> i & 1) sub += a[i];
        }
        res = min(res, abs(sum - sub - sub));
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