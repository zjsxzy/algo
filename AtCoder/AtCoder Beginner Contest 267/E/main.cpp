#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<LL> sum(n);
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        sum[u] += a[v];
        sum[v] += a[u];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    auto check = [&](LL k) {
        queue<int> q;
        vector<LL> curr = sum;
        vector<int> vst(n);
        for (int i = 0; i < n; i++) {
            if (curr[i] <= k) {
                vst[i] = true;
                q.push(i);
            }
        }
        while (!q.empty()) {
            int u = q.front(); q.pop();
            // delete vertex u
            for (auto v: adj[u]) {
                curr[v] -= a[u];
                if (curr[v] <= k && !vst[v]) {
                    vst[v] = true;
                    q.push(v);
                }
            }
        }
        for (int i = 0; i < n; i++) if (!vst[i]) return false;
        return true;
    };
    LL lo = 0, hi = 1e15;
    while (lo <= hi) {
        LL mid = (lo + hi) >> 1;
        if (check(mid)) hi = mid - 1;
        else lo = mid + 1;
    }
    cout << lo << endl;
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

