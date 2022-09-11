#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> siz(n);
    vector<int> p(n);
    for (int i = 1; i < n; i++) {
        cin >> p[i];
        p[i]--;
        siz[p[i]]++;
    }
    while (q--) {
        int m;
        cin >> m;
        set<int> st;
        int res = 0;
        while (m--) {
            int u;
            cin >> u;
            u--;
            st.insert(u);
            res += siz[u] + 1;
        }
        for (auto u: st) if (u > 0 && st.count(p[u])) res -= 2;
        cout << res << endl;
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

