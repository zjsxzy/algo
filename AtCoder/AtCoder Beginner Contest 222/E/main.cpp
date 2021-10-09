#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int maxn = 1005;
const int maxk = 100005;
const int mod = 998244353;
int n, m, k;
int a[maxn], cnt[maxn];
int dp[2][maxk];
vector<pair<int, int>> adj[maxn];
vector<int> path;

void dfs(int u, int p, int target) {
    if (u == target) {
        for (auto p: path) {
            cnt[p]++;
        }
        return;
    }
    for (auto v: adj[u]) {
        if (v.first != p) {
            path.emplace_back(v.second);
            dfs(v.first, u, target);
            path.pop_back();
        }
    }
}

void traverse(int u, int v) {
    path.clear();
    dfs(u, 0, v);
}

void solve() {
    cin >> n >> m >> k;
    k = abs(k);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    vector<pair<int, int>> edges;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        edges.emplace_back(u, v);
        adj[u].emplace_back(v, i);
        adj[v].emplace_back(u, i);
    }
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i < m; i++) {
        traverse(a[i - 1], a[i]);
    }
    /*
    for (int i = 1; i < n; i++) {
        cout << i << " " << edges[i - 1].first << " " << edges[i - 1].second << " " << cnt[i] << endl;
    }
    */
    int sum = 0;
    for (int i = 1; i < n; i++) sum += cnt[i];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= sum; j++) {
            dp[i % 2][j] = dp[1 - i % 2][j];
            if (j - cnt[i] >= 0) {
                dp[i % 2][j] = (dp[i % 2][j] + dp[1 - i % 2][j - cnt[i]]) % mod;
            }
        }
    }
    if (sum >= k) {
        if ((sum - k) & 1) cout << 0 << endl;
        else cout << dp[(n - 1) % 2][(sum - k) / 2] << endl;
    } else {
        cout << 0 << endl;
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

