#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int inf = INT_MAX;
const int maxn = 505;
int a[maxn][maxn], g[maxn][maxn];

void solve() {
    int n;
    cin >> n;
    memset(g, 0, sizeof(g));
    for (int i = 1; i <= n; i++) {
        int pos;
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if (a[i][j] == i) pos = j;
        }
        for (int j = 1; j <= pos; j++) {
            g[i][a[i][j]] = 1;
        }
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                g[i][j] |= (g[i][k] & g[k][j]);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (g[a[i][j]][i]) {
                cout << a[i][j] << endl;
                break;
            }
        }
    }
}

int main() {
    solve();
    return 0;
}

