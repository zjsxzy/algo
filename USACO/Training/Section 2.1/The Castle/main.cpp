/*
ID: frankzh1
TASK: castle
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int MAXN = 55;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
char dir[4] = {'W', 'N', 'E', 'S'};
int n, m;
int mat[MAXN][MAXN], color[MAXN][MAXN];

void dfs(int i, int j, int c) {
    color[i][j] = c;
    for (int k = 0; k < 4; k++) {
        if (!(mat[i][j] & (1 << k))) { // no wall
            int x = i + dx[k], y = j + dy[k];
            if (x >= 0 && x < n && y >= 0 && y < m && !color[x][y]) {
                dfs(x, y, c);
            }
        }
    }
}

void solve() {
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }
    memset(color, 0, sizeof(color));
    int num = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!color[i][j]) {
                num++;
                dfs(i, j, num);
            }
        }
    }
    cout << num << endl;

    vector<int> sz(num + 1);
    int mx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            sz[color[i][j]]++;
            if (sz[color[i][j]] > mx) {
                mx = sz[color[i][j]];
            }
        }
    }
    cout << mx << endl;

    mx = 0;
    pair<int, int> location;
    int direction;
    for (int j = 0; j < m; j++) {
        for (int i = n - 1; i >= 0; i--) {
            for (int k = 0; k < 4; k++) {
                if (k == 0 || k == 3) continue;
                int x = i + dx[k], y = j + dy[k];
                if (x >= 0 && x < n && y >= 0 && y < m && (mat[i][j] & (1 << k))) {
                    if (color[i][j] != color[x][y]) {
                        if (sz[color[i][j]] + sz[color[x][y]] > mx) {
                            mx = sz[color[i][j]] + sz[color[x][y]];
                            location = {i + 1, j + 1};
                            direction = k;
                        }
                    }
                }
            }
        }
    }
    cout << mx << endl;
    cout << location.first << " " << location.second << " " << dir[direction] << endl;
}

int main() {
    freopen("castle.in", "r", stdin);
    freopen("castle.out", "w", stdout);
    solve();
    return 0;
}

