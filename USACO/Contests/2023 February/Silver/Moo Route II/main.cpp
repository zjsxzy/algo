#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<tuple<int, int, int>>> g(n);
    for (int i = 0; i < m; i++) {
        int c, r, d, s;
        cin >> c >> r >> d >> s;
        c--; d--;
        g[c].push_back(make_tuple(r, d, s));
    }
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    const int inf = 1e9;
    vector<int> ans(n, inf);
    set<pair<int, int>> st;
    ans[0] = 0;
    st.insert({0, 0});
    for (auto p: g[0]) {
        int r = get<0>(p), d = get<1>(p), s = get<2>(p);
        ans[d] = min(ans[d], s);
        st.insert({s, d});
    }
    while (!st.empty()) {
        auto x = st.begin();
        int t = x->first, u = x->second;
        // cout << u + 1 << ' ' << t << endl;
        st.erase(st.begin());
        for (auto p: g[u]) {
            int r = get<0>(p), d = get<1>(p), s = get<2>(p);
            // cout << u + 1 << ' ' << r << ' ' << d + 1 << ' ' << s << endl;
            if (r >= t + a[u] && s < ans[d]) {
                ans[d] = s;
                st.insert({s, d});
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (ans[i] == inf) cout << -1 << endl;
        else cout << ans[i] << endl;
    }
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