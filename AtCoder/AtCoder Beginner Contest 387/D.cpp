#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MAXN = 1005;
int d[MAXN][MAXN][2];
string S[MAXN];
int H, W;

bool inside(int i, int j) {
    return (i >= 0) && (i < H) && (j >= 0) && (j < W);
}

void solve() {
    cin >> H >> W;
    pair<int, int> st, ed;
    for (int i = 0; i < H; i++) {
        cin >> S[i];
        for (int j = 0; j < W; j++) {
            if (S[i][j] == 'S') {
                st = make_pair(i, j);
            } else if (S[i][j] == 'G') {
                ed = make_pair(i, j);
            }
        }
    }
    // cout << st.first << ' ' << st.second << '\n';
    // cout << ed.first << ' ' << ed.second << '\n';
    const int inf = 1e9;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            d[i][j][0] = d[i][j][1] = inf;
        }
    }
    queue<pair<pair<int, int>, int> > q;
    d[st.first][st.second][0] = d[st.first][st.second][1] = 0;
    q.push({{st.first, st.second}, 0});
    q.push({{st.first, st.second}, 1});
    vector dx = {0, 0, -1, 1};
    vector dy = {-1, 1, 0, 0};
    while (!q.empty()) {
        auto t = q.front(); q.pop();
        int x = t.first.first, y = t.first.second, dir = t.second;
        // cout << x << ' ' << y << ' ' << dir << ' ' << d[x][y][dir] << '\n';
        if (t.first == ed) {
            cout << d[x][y][dir] << '\n';
            return;
        }
        for (int k = 0; k < 4; k++) {
            if (dir == 0 && k >= 2) continue;
            if (dir == 1 && k < 2) continue;
            int nx = x + dx[k], ny = y + dy[k];
            // cout << nx << ' ' << ny << '\n';
            // if (inside(nx, ny)) {
                // cout << S[nx][ny] << ' ' << d[x][y][dir] + 1 << ' ' << d[nx][ny][dir ^ 1] << '\n';
            // }
            if (inside(nx, ny) && S[nx][ny] != '#' && d[x][y][dir] + 1 < d[nx][ny][dir ^ 1]) {
                d[nx][ny][dir ^ 1] = d[x][y][dir] + 1;
                q.push({{nx, ny}, dir ^ 1});
            }
        }
    }
    cout << -1 << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}