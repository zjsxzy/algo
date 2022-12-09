#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int mod = 1e9 + 7;
const int maxn = 100005;
int n, k;
int color[maxn];
LL dp[maxn][3], tot[maxn];
vector<int> adj[maxn];

void dfs(int u, int fa) {
    for (auto& v: adj[u]) {
        if (v == fa) continue;
        dfs(v, u);
        for (int j = 0; j < 3; j++) {
            dp[u][j] = dp[u][j] * (tot[v] - dp[v][j] + mod) % mod;
        }
    }
    for (int j = 0; j < 3; j++) {
        tot[u] = (tot[u] + dp[u][j]) % mod;
    }
}

void solve() {
    cin >> n >> k;
    for (int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        adj[i].emplace_back(x);
        adj[x].emplace_back(i);
    }
    for (int i = 1; i <= n; i++) {
        color[i] = -1;
    }
    for (int i = 0; i < k; i++) {
        int u, c;
        cin >> u >> c;
        color[u] = c;
    }
    for (int i = 1; i <= n; i++) {
        if (color[i] == -1) {
            for (int j = 0; j < 3; j++) {
                dp[i][j] = 1;
            }
        } else {
            dp[i][color[i]] = 1;
        }
    }
    dfs(1, 0);
    cout << tot[1] << endl;
}

int main() {
    solve();
    return 0;
}

