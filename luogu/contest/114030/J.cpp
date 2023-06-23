#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int n, x, y, p, cycle;
vector<int> vis, c, deg;
vector<vector<int>> g;

void dfs(int u) {
    if (vis[u]) return;
    vis[u] = true;
    cycle++;
    int v = ((LL)u * x + y) % p;
    dfs(v);
    c[u] = cycle;
}

void solve() {
    std::cin >> n >> x >> y >> p;
    c.assign(p, 0);
    deg.assign(p, 0);
    vis.assign(p, 0);
    g.assign(p, {});
    for (int u = 0; u < p; u++) {
        int v = ((LL)u * x + y) % p;
        deg[v]++;
    }
    queue<int> que;
    for (int i = 0; i < p; i++) {
        if (deg[i] == 0) {
            que.push(i);
        }
    }
    while (!que.empty()) {
        int u = que.front(); que.pop();
        vis[u] = true;
        int v = ((LL)u * x + y) % p;
        deg[v]--;
        if (deg[v] == 0) que.push(v);
    }
    for (int i = 0; i < p; i++) {
        if (vis[i]) continue;
        cycle = 0;
        dfs(i);
    }
    vector<int> ans(p + 1);
    for (int i = 0; i < n; i++) {
        int u;
        std::cin >> u;
        if (u < p) ans[c[u]]++;
    }
    int q;
    std::cin >> q;
    while (q--) {
        int k;
        std::cin >> k;
        int res = 0;
        for (int i = 1; i <= p; i++) {
            if (k % i == 0) res += ans[i];
        }
        std::cout << res << endl;
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