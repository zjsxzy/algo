#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

double dp[1 << 15][1 << 6][20];

double dist(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<double> x(n), y(n), p(m), q(m);
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
    for (int i = 0; i < m; i++) cin >> p[i] >> q[i];
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < (1 << m); j++) {
            for (int k = 0; k < n + m; k++) {
                dp[i][j][k] = 1e20;
            }
        }
    }
    for (int i = 0; i < n + m; i++) {
        if (i < n) {
            dp[1 << i][0][i] = dist(x[i], y[i], 0, 0);
        } else {
            dp[0][1 << (i - n)][i] = dist(p[i - n], q[i - n], 0, 0);
        }
    }
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < (1 << m); j++) {
            double d = pow(2, __builtin_popcount(j));
            for (int k = 0; k < n + m; k++) {
                if (dp[i][j][k] < 1e20) {
                    double xx, yy;
                    if (k < n) {
                        xx = x[k], yy = y[k];
                    } else {
                        xx = p[k - n], yy = q[k - n];
                    }
                    for (int u = 0; u < n; u++) {
                        if (!(i >> u & 1)) {
                            dp[i | (1 << u)][j][u] = min(dp[i | (1 << u)][j][u], dp[i][j][k] + dist(x[u], y[u], xx, yy) / d);
                        }
                    }
                    for (int v = 0; v < m; v++) {
                        if (!(j >> v & 1)) {
                            dp[i][j | (1 << v)][n + v] = min(dp[i][j | (1 << v)][n + v], dp[i][j][k] + dist(p[v], q[v], xx, yy) / d);
                        }
                    }
                }
            }
        }
    }
    double res = 1e20;
    for (int j = 0; j < (1 << m); j++) {
        double d = pow(2, __builtin_popcount(j));
        for (int k = 0; k < n + m; k++) {
            double xx, yy;
            if (k < n) {
                xx = x[k], yy = y[k];
            } else {
                xx = p[k - n], yy = q[k - n];
            }
            res = min(res, dp[(1 << n) - 1][j][k] + dist(xx, yy, 0, 0) / d);
        }
    }
    printf("%.9f\n", res);
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

