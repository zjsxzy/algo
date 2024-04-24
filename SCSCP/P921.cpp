#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 1; i < n; i++) {
        int p;
        cin >> p;
        p--;
        g[i].push_back(p);
        g[p].push_back(i);
    }
    int res = 0;
    vector<int> vis(n), grand(n);
    function<void(int, int)> dfs = [&](int u, int fa) {
        for (auto v: g[u]) {
            if (v == fa) continue;
            grand[v] = u;
            dfs(v, u);
        }
        if (!vis[u]) {
            res++;
            int pos = grand[u];
            vis[pos] = 1;
            for (auto v: g[pos]) vis[v] = true;
        }
    };
    dfs(0, -1);
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