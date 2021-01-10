#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int MAXN = 200005;
int n, m;
int a[MAXN], deg[MAXN], dp[MAXN];
vector<int> adj[MAXN];

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        deg[i] = 0;
        dp[i] = INT_MAX;
    }
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        adj[x].push_back(y);
        deg[y]++;
    }

    int res = INT_MIN;
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (deg[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (dp[u] != INT_MAX) res = max(res, a[u] - dp[u]);
        dp[u] = min(dp[u], a[u]);
        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];
            dp[v] = min(dp[v], dp[u]);
            deg[v]--;
            if (deg[v] == 0) q.push(v);
        }
    }
    cout << res << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

