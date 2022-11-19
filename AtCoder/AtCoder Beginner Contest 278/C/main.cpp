#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, q;
    cin >> n >> q;
    map<int, set<int>> f;
    for (int i = 0; i < q; i++) {
        int t, a, b;
        cin >> t >> a >> b;
        if (t == 1) {
            f[a].insert(b);
        } else if (t == 2) {
            if (f[a].count(b)) f[a].erase(b);
        } else {
            if (f[a].count(b) && f[b].count(a)) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
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

