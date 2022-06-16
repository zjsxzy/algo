#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 200005;
vector<vector<int>> adj;
int l[maxn], r[maxn], p[maxn], dp[maxn];
LL sum[maxn];

void dfs(int u, int f) {
    for (auto v: adj[u]) {
        if (v == f) continue;
        dfs(v, u);
        sum[u] += sum[v];
        dp[u] += dp[v];
    }
    if (sum[u] < l[u]) {
        sum[u] = r[u];
        dp[u]++;
    }
    if (sum[u] > r[u]) sum[u] = r[u];
}
void solve() {
    int n;
    cin >> n;
    adj.assign(n + 1, {});
    memset(dp, 0, sizeof(dp));
    memset(sum, 0, sizeof(sum));
    for (int i = 2; i <= n; i++) {
        cin >> p[i];
        adj[i].push_back(p[i]);
        adj[p[i]].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        cin >> l[i] >> r[i];
    }
    dfs(1, 0);
    cout << dp[1] << endl;
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("in.txt", "r", stdin);
#endif
   int ts = 1;
   cin >> ts;
   for (int t = 1; t <= ts; t++) {
       solve();
   }
   return 0;
}

