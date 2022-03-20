#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int maxn = 2005;
const int mod = 998244353;
int dp[maxn][maxn][2];
vector<int> adj[maxn];

void solve() {
    int n, m, k, s, t, x;
    cin >> n >> m >> k >> s >> t >> x;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dp[0][s][0] = 1;
    for (int i = 0; i < k; i++) {
        for (int u = 1; u <= n; u++) {
            for (int d = 0; d < 2; d++) {
                if (dp[i][u][d]) {
                    for (auto v: adj[u]) {
                        dp[i + 1][v][d ^ (v == x)] += dp[i][u][d];
                        dp[i + 1][v][d ^ (v == x)] %= mod;
                    }
                }
            }
        }
    }
    cout << dp[k][t][0] << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

