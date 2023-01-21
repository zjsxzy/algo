#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 305;
LL d[maxn][maxn][maxn], f[maxn][maxn][maxn], a[maxn];

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) d[0][i][j] = 0;
            else d[0][i][j] = 1e9;
        }
    }
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        s = ' ' + s;
        for (int j = 1; j <= n; j++) {
            if (s[j] == 'Y') d[0][i][j] = 1;
        }
    }
    memset(f, 0, sizeof(f));
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (d[k - 1][i][k] + d[k - 1][k][j] < d[k - 1][i][j]) {
                    d[k][i][j] = d[k - 1][i][k] + d[k - 1][k][j];
                    f[k][i][j] = f[k - 1][i][k] + f[k - 1][k][j] + a[k];
                } else if (d[k - 1][i][k] + d[k - 1][k][j] == d[k - 1][i][j] && f[k - 1][i][k] + f[k - 1][k][j] + a[k] > f[k - 1][i][j]) {
                    d[k][i][j] = d[k - 1][i][k] + d[k - 1][k][j];
                    f[k][i][j] = f[k - 1][i][k] + f[k - 1][k][j] + a[k];
                } else {
                    d[k][i][j] = d[k - 1][i][j];
                    f[k][i][j] = f[k - 1][i][j];
                }
            }
        }
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v;
        if (d[n][u][v] == 1e9) {
            cout << "Impossible" << endl;
        } else {
            cout << d[n][u][v] << ' ' << f[n][u][v] << endl;
        }
    }
}

int main() {
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}