#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    vector<int> deg(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        // b->a
        g[b].push_back(a);
        deg[a]++;
    }
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (deg[i] == 0) {
            q.push(i);
        }
    }
    vector<int> ans(n);
    int x = n;
    if ((int)q.size() != 1) {
        cout << "No" << endl;
        return;
    }
    while (!q.empty()) {
        if ((int)q.size() != 1) {
            cout << "No" << endl;
            return;
        }
        int u = q.front(); q.pop();
        // cout << u << endl;
        ans[u] = x;
        x--;
        for (auto v: g[u]) {
            deg[v]--;
            if (deg[v] == 0) q.push(v);
        }
    }
    cout << "Yes" << endl;
    for (auto x: ans) cout << x << ' ';
    cout << endl;
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