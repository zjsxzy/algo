#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (auto& s: grid) cin >> s;
    int res = 0;
    vector<vector<int>> vst(n, vector<int>(m));
    vector<int> dx = {0, 0, -1, 1};
    vector<int> dy = {-1, 1, 0, 0};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vst[i][j] || grid[i][j] == '#') continue;
            res++;
            queue<pair<int, int>> q;
            q.push({i, j});
            while (!q.empty()) {
                auto u = q.front(); q.pop();
                for (int k = 0; k < 4; k++) {
                    int x = u.first + dx[k], y = u.second + dy[k];
                    if (x >= 0 && x < n && y >= 0 && y < m && !vst[x][y] && grid[x][y] == '.') {
                        vst[x][y] = 1;
                        q.push({x, y});
                    }
                }
            }
        }
    }
    cout << res << endl;
}

int main() {
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}