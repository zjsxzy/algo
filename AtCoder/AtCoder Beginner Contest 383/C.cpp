#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int H, W, D;
    cin >> H >> W >> D;
    vector<string> S(H);
    queue<pair<int, int>> q;
    const int inf = 1e9;
    vector<vector<int>> d(H, vector<int>(W, inf));
    for (int i = 0; i < H; i++) {
        cin >> S[i];
        for (int j = 0; j < W; j++) {
            if (S[i][j] == 'H') {
                d[i][j] = 0;
                q.push({i, j});
            }
        }
    }
    vector dx = {0, 0, -1, 1};
    vector dy = {-1, 1, 0, 0};
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx >= 0 && nx < H && ny >= 0 && ny < W && S[nx][ny] == '.' && d[x][y] + 1 < d[nx][ny]) {
                d[nx][ny] = d[x][y] + 1;
                if (d[nx][ny] <= D) {
                    q.push({nx, ny});
                }
            }
        }
    }
    int res = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            res += (d[i][j] <= D);
        }
    }
    cout << res << endl;
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