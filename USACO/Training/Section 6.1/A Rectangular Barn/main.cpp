/*
ID: frankzh1
TASK: rectbarn
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int maxn = 3005;
int R, C, p;
int l[2][maxn], r[2][maxn], h[2][maxn];
bool a[maxn][maxn];

inline int min(int a, int b) {
    if (a < b && a != 0) return a;
    else return b;
}

void solve() {
    cin >> R >> C >> p;
    for (int i = 0; i < p; i++) {
        int x, y;
        cin >> x >> y;
        a[x][y] = 1;
    }
    int res = 0;
    for (int i = 1; i <= R; i++) {
        int tot = 0;
        for (int j = 1; j <= C; j++) {
            if (a[i][j] == 0) {
                h[i % 2][j] = h[(i - 1) % 2][j] + 1;
                l[i % 2][j] = min(l[(i - 1) % 2][j], ++tot);
            } else {
                h[i % 2][j] = 0;
                l[i % 2][j] = 0;
                tot = 0;
            }
        }

        tot = 0;
        for (int j = C; j >= 1; j--) {
            if (a[i][j] == 0) {
                r[i % 2][j] = min(r[(i - 1) % 2][j], ++tot);
                res = max(res, h[i % 2][j] * (r[i % 2][j] + l[i % 2][j] - 1));
            } else {
                r[i % 2][j] = 0;
                tot = 0;
            }
        }
    }
    cout << res << endl;
}

int main() {
    freopen("rectbarn.in", "r", stdin);
    freopen("rectbarn.out", "w", stdout);
    solve();
    return 0;
}

