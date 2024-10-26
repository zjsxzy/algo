#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> d(m + 1);
    d[1] = 1;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        d[r] = max(d[r], l + 1);
    }
    for (int r = 1; r <= m; r++) {
        d[r] = max(d[r], d[r - 1]);
    }
    LL res = 0;
    for (int r = 1; r <= m; r++) {
        res += r - d[r] + 1;
    }
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