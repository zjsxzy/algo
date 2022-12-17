#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> color(n, -1);
    bool flag = true;
    LL tot = 0;
    vector<LL> cntc(2);
    function<void(int, int)> dfs = [&](int u, int c) {
        if (!flag) return;
        color[u] = c;
        cntc[c]++;
        tot++;
        for (auto v: adj[u]) {
            if (color[v] != -1) {
                if (color[v] == c) {
                    flag = false;
                    return;
                }
                continue;
            }
            dfs(v, 1 - c);
        }
    };
    LL res1 = 0, res2 = 0;
    for (int i = 0; i < n; i++) {
        if (color[i] == -1) {
            dfs(i, 0);
            // cout << tot << ' ' << cntc[0] << ' ' << cntc[1] << endl;
            res1 += tot * (n - tot);
            res2 += cntc[0] * cntc[1];
            tot = 0;
            cntc[0] = cntc[1] = 0;
        }
    }
    if (!flag) {
        cout << 0 << endl;
        return;
    }
    cout << res1 / 2 + res2 - m << endl;
}

int main() {
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}