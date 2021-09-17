/*
ID: frankzh1
TASK: betsy
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

int n;
int step[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
bool vis[9][9];

bool inside(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

int countOutDegree(int x, int y) {
    int count = 0;
    for (int i = 0; i < 4; i++) {
        int x1 = x + step[i][0], y1 = y + step[i][1];
        if (inside(x1, y1) && !vis[x1][y1]) count++;
    }
    return count;
}

bool checkDeadEnd(int x, int  y) {
    if ((!inside(x + 1, y) || vis[x + 1][y]) && (!inside(x - 1, y) || vis[x - 1][y])) {
        if (inside(x, y - 1) && !vis[x][y - 1] && inside(x, y + 1) && !vis[x][y + 1]) {
            return true;
        }
    }
    if ((!inside(x, y - 1) || vis[x][y - 1]) && (!inside(x, y + 1) || vis[x][y + 1])) {
        if (inside(x - 1, y) && !vis[x - 1][y] && inside(x + 1, y) && !vis[x + 1][y]) {
            return true;
        }
    }
    return false;
}

int dfs(int x, int y, int dep) {
    if (dep == n * n) {
        if (x == n - 1 && y == 0) {
            return 1;
        }
        return 0;
    }
    if (x == n - 1 && y == 0) return 0;
    if (checkDeadEnd(x, y)) return 0;

    vis[x][y] = true;
    int count = 0, idx = -1;
    for (int i = 0; i < 4; i++) {
        int x1 = x + step[i][0], y1 = y + step[i][1];
        if (inside(x1, y1) && !vis[x1][y1] && countOutDegree(x1, y1) == 1) {
            if (x1 == n - 1 && y1 == 0) continue;
            count++;
            idx = i;
        }
    }
    int res = 0;
    if (count == 1) {
        res += dfs(x + step[idx][0], y + step[idx][1], dep + 1);
    } else {
        for (int i = 0; i < 4; i++) {
            int x1 = x + step[i][0], y1 = y + step[i][1];
            if (inside(x1, y1) && !vis[x1][y1]) {
                res += dfs(x1, y1, dep + 1);
            }
        }
    }
    vis[x][y] = false;
    return res;
}
void solve() {
    cin >> n;
    memset(vis, 0, sizeof(vis));
    int ans = dfs(0, 0, 1);
    printf("%d\n", ans);
}

int main() {
    freopen("betsy.in", "r", stdin);
    freopen("betsy.out", "w", stdout);
    solve();
    return 0;
}

