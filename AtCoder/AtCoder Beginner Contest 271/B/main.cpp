#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> a(n);
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        while (m--) {
            int x;
            cin >> x;
            a[i].push_back(x);
        }
    }
    while (q--) {
        int s, t;
        cin >> s >> t;
        cout << a[s - 1][t - 1] << endl;
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

