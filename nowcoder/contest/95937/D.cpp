#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> c(n);
    for (auto&x : c) cin >> x;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> vst(n);
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (vst[i]) continue;
        queue<int> q;
        q.push(i);
        vst[i] = true;
        map<int, int> cnt;
        cnt[c[i]]++;
        int sz = 1;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (auto v: g[u]) {
                if (!vst[v]) {
                    sz++;
                    vst[v] = true;
                    q.push(v);
                    cnt[c[v]]++;
                }
            }
        }
        int mx = 0;
        for (auto [k, v]: cnt) {
            mx = max(mx, v);
        }
        // cout << mx << ' ' << sz << endl;
        res += sz - mx;
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