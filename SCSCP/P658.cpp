#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<int> c(n), vst(n);
    int colors = 0;
    for (auto& x: c) {
        cin >> x;
        x--;
        if (!vst[x]) {
            colors++;
        }
        vst[x] = 1;
    }
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int p;
        cin >> p;
        p--;
        adj[i].push_back(p);
        adj[p].push_back(i);
    }
    LL cnt = 0;
    vector<int> sum(n), size(n);
    function<void(int, int)> dfs = [&](int u, int p) {
        size[u] = 1;
        int temp = 0;
        if (sum[c[u]] != 0) {
            temp = sum[c[u]];
            sum[c[u]] = 0;
        }
        for (auto v: adj[u]) {
            if (v == p) continue;
            dfs(v, u);
            size[u] += size[v];
            cnt += (LL)(size[v] - sum[c[u]]) * (size[v] - sum[c[u]] - 1) / 2;
            sum[c[u]] = 0;
        }
        sum[c[u]] = size[u] + temp;
    };
    dfs(0, -1);
    for (int i = 0; i < n; i++) {
        if (!vst[i]) continue;
        cnt += (LL)(n - sum[i]) * (n - sum[i] - 1) / 2;
    }
    cout << (LL)n * (n - 1) / 2 * colors - cnt << endl;
}

int main() {
   int ts = 1;
   // cin >> ts;
   for (int t = 1; t <= ts; t++) {
       solve();
   }
   return 0;
}

