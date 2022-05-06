#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int res = 0;
    for (int j = 0; j < 30; j++) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] >> j & 1) cnt++;
        }
        if (cnt & 1) res |= (1 << j);
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

