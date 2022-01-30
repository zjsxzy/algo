#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int maxn = 1005;
const LL mod = 998244353;
int n, m;
int dp[maxn][11][11][11];

void add(int& x, int a) {
    x += a;
    x %= mod;
}

void solve() {
    cin >> n >> m;
    dp[0][0][0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int k = 0; k <= m; k++) {
                for (int l = 0; l <= m; l++) {
                    for (int p = 1; p <= m; p++) {
                        int tj = j, tk = k, tl = l;
                        if (tl && p > tl) continue; // greater than 3
                        else if (tk && p > tk) tl = (tl ? min(tl, p) : p);
                        else if (tj && p > tj) tk = (tk ? min(tk, p) : p);
                        else tj = (tj ? min(tj, p) : p);
                        add(dp[i][tj][tk][tl], dp[i - 1][j][k][l]);
                    }
                }
            }
        }
    }
    int res = 0;
    for (int j = 1; j <= m; j++) {
        for (int k = 1; k <= m; k++) {
            for (int l = 1; l <= m; l++) {
                add(res, dp[n][j][k][l]);
            }
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

