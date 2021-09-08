/*
ID: frankzh1
TASK: tour
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int maxn = 105;
int dp[maxn][maxn], g[maxn][maxn];

void solve() {
    int n, m;
    cin >> n >> m;
    memset(g, 0, sizeof(g));
    map<string, int> name;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        name[s] = i;
    }
    for (int i = 0; i < m; i++) {
        string u, v;
        cin >> u >> v;
        g[name[u]][name[v]] = g[name[v]][name[u]] = 1;
    }
    memset(dp, -63, sizeof(dp));
    dp[1][1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            for (int k = 1; k < j; k++) {
                if (g[j][k]) {
                    dp[i][j] = max(dp[i][j], dp[i][k] + 1);
                    dp[j][i] = dp[i][j];
                }
            }
        }
    }
    int res = 1;
    for (int i = 1; i <= n; i++) {
        if (g[i][n]) res = max(res, dp[i][n]);
    }
    cout << res << endl;
}

int main() {
    freopen("tour.in", "r", stdin);
    freopen("tour.out", "w", stdout);
    solve();
    return 0;
}

