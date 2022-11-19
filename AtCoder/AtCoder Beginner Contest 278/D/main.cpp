#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<LL> t(n), add(n);
    for (int i = 0; i < n; i++) {
        cin >> add[i];
        t[i] = 0;
    }
    int q, last = -1;
    cin >> q;
    LL ans = 0;
    for (int i = 1; i <= q; i++) {
        int type, idx, x;
        cin >> type;
        if (type == 1) {
            cin >> ans;
            last = i;
        } else if (type == 2) {
            cin >> idx >> x;
            idx--;
            if (t[idx] < last) {
                t[idx] = i;
                add[idx] = 0;
            }
            add[idx] += x;
        } else {
            cin >> idx;
            idx--;
            if (t[idx] < last) {
                add[idx] = 0;
            }
            cout << ans + add[idx] << endl;
        }
    }
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


