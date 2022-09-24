#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    x--; y--;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> ans;
    vector<int> vst(n);
    function<void(int)> dfs = [&](int u) {
        if (u == y) {
            cout << x + 1;
            for (auto v: ans) cout << ' ' << v + 1;
            cout << endl;
            return;
        }
        vst[u] = true;
        for (auto v: adj[u]) {
            if (vst[v]) continue;
            ans.push_back(v);
            dfs(v);
            ans.pop_back();
        }
    };
    dfs(x);
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("in.txt", "r", stdin);
#endif
   int ts = 1;
   // cin >> ts;
   for (int t = 1; t <= ts; t++) {
       solve();
   }
   return 0;
}

