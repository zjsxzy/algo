#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n1, n2, m1, m2;
    cin >> n1 >> n2 >> m1 >> m2;
    auto topo = [&](int n, int m) {
        vector<vector<int>> g(n);
        vector<int> deg(n);
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            g[u].push_back(v);
            deg[v]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (deg[i] == 0) q.push(i);
        }
        vector<bitset<2000>> dp(n);
        dp[0][0] = 1;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (auto v: g[u]) {
                dp[v] |= (dp[u] << 1);
                deg[v]--;
                if (deg[v] == 0) q.push(v);
            }
        }
        return dp;
    };
    vector dp1 = topo(n1, m1);
    vector dp2 = topo(n2, m2);
    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        bool flag = false;
        for (int i = 0; i <= 1000; i++) {
            if (x - i >= 0 && dp1[n1 - 1][i] && dp2[n2 - 1][x - i]) {
                flag = true;
                break;
            }
        }
        if (flag) cout << "Yes" << endl;
        else cout << "No" << endl;
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