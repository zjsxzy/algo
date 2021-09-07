/*
ID: frankzh1
TASK: snail
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int maxn = 125;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int m, n, res;
int mat[maxn][maxn];

void dfs(int x, int y, int dir, int steps) {
    res = max(res, steps);
    if (mat[x + dx[dir]][y + dy[dir]] == 1) {
        mat[x][y] = 2;
        dfs(x + dx[dir], y + dy[dir], dir, steps + 1);
        mat[x][y] = 1;
    } else if (mat[x + dx[dir]][y + dy[dir]] == 0) {
        for (int i = 0; i < 4; i++) {
            if (mat[x + dx[i]][y + dy[i]] == 1 && (i + dir) % 2 != 0) {
                mat[x][y] = 2;
                dfs(x + dx[i], y + dy[i], i, steps + 1);
                mat[x][y] = 1;
            }
        }
    }
}

void solve() {
    int m;
    cin >> n >> m;
    memset(mat, 0, sizeof(mat));
    for (int i = 0; i < m; i++) {
        char c;
        int a;
        cin >> c >> a;
        mat[c - 'A' + 1][a] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            mat[i][j] = 1 - mat[i][j];
        }
    }
    res = 0;
    dfs(1, 1, 0, 1);
    dfs(1, 1, 1, 1);
    cout << res << endl;
}

int main() {
    freopen("snail.in", "r", stdin);
    freopen("snail.out", "w", stdout);
    solve();
    return 0;
}

