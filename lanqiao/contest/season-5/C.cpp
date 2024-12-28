#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<string> g(n);
    for (int i = 0; i < n; i++) cin >> g[i];
    vector dx = {1, 1, -1, -1};
    vector dy = {-1, 1, -1, 1};
    auto inside = [&] (int i, int j) {
        return i >= 0 && i < n && j >= 0 && j < n;
    };
    int res = 0;
    function<void(int, int, int)> dfs = [&](int x, int y, int c) {
        // cout << x << ' ' << y << ' ' << c << '\n';
        res = max(res, c);
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k], ny = y + dy[k];
            int nnx = nx + dx[k], nny = ny + dy[k];
            if (inside(nx, ny) && g[nx][ny] == 'Q' && inside(nnx, nny) && g[nnx][nny] == '.') {
                g[x][y] = '.';
                g[nx][ny] = '.';
                g[nnx][nny] = 'L';
                dfs(nnx, nny, c + 1);
                g[nnx][nny] = '.';
                g[nx][ny] = 'Q';
                g[x][y] = 'L';
            }
        }
    };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (g[i][j] == 'L') {
                dfs(i, j, 0);
            }
        }
    }
    // for (auto s: g) cout << s << '\n';
    cout << res << '\n';
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