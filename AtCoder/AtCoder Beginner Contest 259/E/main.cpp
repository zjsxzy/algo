#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    map<int, array<int, 2>> maxe;
    vector<vector<array<int, 2>>> a(n);
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        a[i].resize(m);
        for (int j = 0; j < m; j++) {
            int p, e;
            cin >> p >> e;
            a[i][j] = {p, e};
            auto& [v, c] = maxe[p];
            if (e > v) {
                v = e;
                c = 1;
            } else if (e == v) {
                c++;
            }
        }
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        bool ok = false;
        for (auto [p, e]: a[i]) {
            if (maxe[p] == array{e, 1}) {
                ok = true;
            }
        }
        res += ok;
    }
    cout << min(res + 1, n) << endl;
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

