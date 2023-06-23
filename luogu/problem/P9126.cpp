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
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sort(g[i].begin(), g[i].end());
    }
    const int inf = 1e9;
    vector<int> ans(n, inf);
    function<void(int, int)> dfs = [&](int x, int ti) {
        if (g[x].size() == 0) return;
        int t = get<0>(g[x].back()), d = get<1>(g[x].back()), s = get<2>(g[x].back());
        while (ti <= t) {
            ans[d] = min(ans[d], s);
            g[x].pop_back();
            dfs(d, s + a[d]);
            if (g[x].empty()) break;
            t = get<0>(g[x].back()), d = get<1>(g[x].back()), s = get<2>(g[x].back());
        }
    };
    ans[0] = 0;
    dfs(0, 0);
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