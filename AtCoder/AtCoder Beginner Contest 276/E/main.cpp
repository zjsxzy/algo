#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int n, m;
vector<string> c;
bool inside(int x, int y) {
    return (x >= 0) && (x < n) && (y >= 0) && (y < m) && (c[x][y] == '.');
}
void solve() {
    cin >> n >> m;
    c.resize(n);
    int stx, sty;
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        for (int j = 0; j < m; j++) {
            if (c[i][j] == 'S') {
                stx = i; sty = j;
            }
        }
    }
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    for (int k = 0; k < 4; k++) {
        queue<pair<int, int>> q;
        int x = stx + dx[k], y = sty + dy[k];
        if (!inside(x, y)) continue;
        q.push({x, y});
        vector<vector<int>> vst(n, vector<int>(m, 0));
        vst[x][y] = 1;
        while (!q.empty()) {
            auto p = q.front(); q.pop();
            for (int d = 0; d < 4; d++) {
                int nx = p.first + dx[d], ny = p.second + dy[d];
                if (inside(nx, ny) && !vst[nx][ny]) {
                    vst[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
        for (int kk = 0; kk < 4; kk++) {
            if (kk != k) {
                int xx = stx + dx[kk], yy = sty + dy[kk];
                if (inside(xx, yy) && vst[xx][yy]) {
                    cout << "Yes" << endl;
                    return;
                }
            }
        }
    }
    cout << "No" << endl;
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

