#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> moves;
    for (int i = -n; i <= n; i++) {
        for (int j = -n; j <= n; j++) {
            if (i * i + j * j == m) moves.emplace_back(i, j);
        }
    }
    vector<vector<int>> ans(n, vector<int>(n, -1));
    ans[0][0] = 0;
    queue<pair<int, int>> q;
    q.push({0, 0});
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (auto [dx, dy]: moves) {
            int nx = x + dx, ny = y + dy;
            if (nx >= 0 && nx < n && ny >= 0 && ny < n && ans[nx][ny] == -1) {
                ans[nx][ny] = ans[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j];
            if (j == n - 1) cout << endl;
            else cout << ' ';
        }
    }
}

int main() {
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}