#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];
    vector<vector<int>> adj(n);
    vector<int> dp(n), deg(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        if (A[u] > A[v]) {
            adj[v].push_back(u);
            deg[u]++;
        } else if (A[v] > A[u]) {
            adj[u].push_back(v);
            deg[v]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (deg[i] == 0) {
            q.push(i);
        }
    }
    int res = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        dp[u]++;
        res = max(res, dp[u]);
        for (auto v: adj[u]) {
            deg[v]--;
            dp[v] += dp[u];
            if (deg[v] == 0) q.push(v);
        }
    }
    cout << res << endl;
}

int main() {
   int ts = 1;
   cin >> ts;
   for (int t = 1; t <= ts; t++) {
       cout << "Case #" << t << ": ";
       solve();
   }
   return 0;
}

