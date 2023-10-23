#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        g[u].push_back({w, v});
        g[v].push_back({w, u});
    }
    for (int i = 0; i < n; i++) {
        sort(g[i].begin(), g[i].end());
    }
    vector<int> vertex;
    auto check = [&](int limit) {
        int st = vertex[0];
        vector<int> vst(n);
        queue<int> q;
        q.push(st);
        vst[st] = true;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (auto [w, v]: g[u]) {
                if (w > limit) break;
                if (!vst[v]) vst[v] = true, q.push(v);
            }
        }
        for (auto x: vertex) if (!vst[x]) return false;
        return true;
    };
    while (q--) {
        int k;
        cin >> k;
        for (int i = 0; i < k; i++) {
            int a;
            cin >> a;
            a--;
            vertex.push_back(a);
        }
        int lo = 0, hi = 1e9, ans = -1;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            if (check(mid)) ans = mid, hi = mid - 1;
            else lo = mid + 1;
        }
        if (ans == -1) cout << "INF" << endl;
        else cout << ans << endl;
        vertex.clear();
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