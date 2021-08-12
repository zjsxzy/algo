/*
ID: frankzh1
TASK: ttwo
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int n = 10;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
vector<string> grid;
struct position {
    int x, y, dir;

    bool operator!= (const position& p) const {
        return x != p.x || y != p.y;
    }

    bool outside(int x, int y) {
        return x < 0 || x == n || y < 0 || y == n;
    }

    void one_step() {
        int xx = x + dx[dir], yy = y + dy[dir];
        if (outside(xx, yy) || grid[xx][yy] == '*') {
            dir = (dir + 1) % 4;
        } else {
            x = xx, y = yy;
        }
    }
};
position cow, farmer;
int vst[15][15][15][15];

void solve() {
    grid.resize(n);
    for (auto &s: grid) {
        cin >> s;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 'C') {
                cow.x = i, cow.y = j, cow.dir = 0;
            }
            if (grid[i][j] == 'F') {
                farmer.x = i, farmer.y = j, farmer.dir = 0;
            }
        }
    }
    int res = 0;
    memset(vst, 0, sizeof(vst));
    while (cow != farmer) {
        vst[cow.x][cow.y][farmer.x][farmer.y]++;
        if (vst[cow.x][cow.y][farmer.x][farmer.y] == 4) {
            cout << 0 << endl;
            return;
        }
        res++;
        cow.one_step();
        farmer.one_step();
    }
    cout << res << endl;
}

int main() {
    freopen("ttwo.in", "r", stdin);
    freopen("ttwo.out", "w", stdout);
    solve();
    return 0;
}

