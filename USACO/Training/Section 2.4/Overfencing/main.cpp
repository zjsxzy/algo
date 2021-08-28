/*
ID: frankzh1
TASK: maze1
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int MAXN = 255;
int dx[4] = {0, 2, 0, -2};
int dy[4] = {2, 0, -2, 0};
int rx[4] = {0, 1, 0, -1};
int ry[4] = {1, 0, -1, 0};
int n, m;
vector<string> grid;
vector<vector<int>> dis;
struct node {
    int x, y, dis;
    node(int x, int y, int dis) {
        this->x = x;
        this->y = y;
        this->dis = dis;
    }
};
vector<node> ex;

bool inside(int x, int y) {
    return x >= 0 && x < 2 * n + 1 && y >= 0 && y < 2 * m + 1;
}

void bfs(node& start) {
    vector<vector<bool>> vst(2 * n + 1, vector<bool>(2 * m + 1));
    queue<node> que;
    vst[start.x][start.y] = true;
    for (int k = 0; k < 4; k++) {
        int xx = start.x + rx[k], yy = start.y + ry[k];
        if (inside(xx, yy) && grid[xx][yy] == ' ') {
            vst[xx][yy] = true;
            que.push(node(xx, yy, 1));
        }
    }
    while (!que.empty()) {
        node now = que.front(); que.pop();
        int x = now.x, y = now.y, d = now.dis;
        dis[x][y] = min(dis[x][y], d);
        for (int k = 0; k < 4; k++) {
            int xx = x + dx[k], yy = y + dy[k];
            int zx = x + rx[k], zy = y + ry[k];
            if (inside(xx, yy) && grid[xx][yy] == ' ' && !vst[xx][yy] && grid[zx][zy] == ' ') {
                vst[xx][yy] = true;
                que.push(node(xx, yy, d + 1));
            }
        }
    }
}

void solve() {
    scanf("%d %d\n", &m, &n);
    grid.resize(2 * n + 1);
    dis.resize(2 * n + 1, vector<int>(2 * m + 1, INT_MAX));
    for (int i = 0; i < 2 * n + 1; i++) {
        getline(cin, grid[i]);
        // cout << i << " " << grid[i] << endl;
        for (int j = 0; j < 2 * m + 1; j++) {
            if (i == 0 || i == 2 * n || j == 0 || j == 2 * m) {
                if (grid[i][j] == ' ') {
                    ex.emplace_back(i, j, 0);
                }
            }
        }
    }
    bfs(ex[0]);
    bfs(ex[1]);
    int res = 0;
    for (int i = 0; i < 2 * n + 1; i++) {
        for (int j = 0; j < 2 * m + 1; j++) {
            if (dis[i][j] != INT_MAX) {
                res = max(res, dis[i][j]);
            }
        }
    }
    cout << res << endl;
}

int main() {
    freopen("maze1.in", "r", stdin);
    freopen("maze1.out", "w", stdout);
    solve();
    return 0;
}

