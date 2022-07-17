#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> p(n), ans(n + 1, -1), fa(n + 1);
    map<int, vector<int>> pile;
    set<int> st;
    for (auto& x: p) cin >> x;
    for (int i = 0; i < n; i++) {
        auto x = st.lower_bound(p[i]);
        if (x == st.end()) {
            fa[p[i]] = p[i];
            pile[p[i]].push_back(p[i]);
        } else {
            int f = *x;
            fa[p[i]] = fa[f];
            pile[fa[p[i]]].push_back(p[i]);
            st.erase(f);
        }
        if (pile[fa[p[i]]].size() == k) {
            for (auto e: pile[fa[p[i]]]) {
                ans[e] = i + 1;
            }
        } else {
            st.insert(p[i]);
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << endl;
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

