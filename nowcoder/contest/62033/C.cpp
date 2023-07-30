#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    LL l, r;
    cin >> n >> l >> r;
    string s;
    cin >> s;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        queue<pair<int, LL>> q;
        q.push({i, s[i] - '0'});
        vector<int> vst(n);
        vst[i] = 1;
        // cout << i << endl;
        while (!q.empty()) {
            auto [u, val] = q.front(); q.pop();
            if (u != i && val >= l && val <= r) res++;
            for (auto v: g[u]) {
                LL nval = (val << 1) + (s[v] - '0');
                // cout << v << ' ' << nval << endl;
                if (!vst[v] && nval <= r) {
                    q.push({v, nval});
                    vst[v] = 1;
                }
            }
        }
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