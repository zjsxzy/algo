#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<int> h(n);
    for (auto& x: h) {
        cin >> x;
    }
    int res = h[0];
    for (int i = 1; i < n; i++) {
        if (h[i] <= res) {
            cout << res << endl;
            return;
        } else {
            res = h[i];
        }
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

