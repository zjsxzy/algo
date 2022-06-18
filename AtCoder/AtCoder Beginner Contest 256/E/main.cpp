#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<int> g, vst, X, C;
int mn;

void dfs(int u) {
    vst[u]++;
    if (vst[u] == 2) {
        return;
    }
    mn = min(mn, C[u]);
    dfs(g[u]);
}

void solve() {
    int n;
    cin >> n;
    X.assign(n + 1, 0);
    C.assign(n + 1, 0);
    g.assign(n + 1, 0);
    vst.assign(n + 1, 0);
    vector<int> deg(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> X[i];
        g[i] = X[i];
        deg[X[i]]++;
    }
    for (int i = 1; i <= n; i++) {
        cin >> C[i];
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (deg[i] == 0) q.push(i);
    }
    while (!q.empty()) {
        int x = q.front(); q.pop();
        deg[X[x]]--;
        if (deg[X[x]] == 0) {
            q.push(X[x]);
        }
    }
    LL res = 0;
    for (int i = 1; i <= n; i++) {
        if (deg[i] && !vst[i]) {
            mn = INT_MAX;
            dfs(i);
            res += mn;
        }
    }
    cout << res << endl;
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

