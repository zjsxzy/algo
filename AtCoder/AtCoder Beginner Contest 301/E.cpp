#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int H, W, T;
    cin >> H >> W >> T;
    vector<string> A(H);
    for (int i = 0; i < H; i++) cin >> A[i];
    string s = "SoG";
    vector<pair<int, int>> p;
    for (auto c: s) {
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (A[i][j] == c) {
                    p.emplace_back(i, j);
                }
            }
        }
    }
    int n = p.size();
    vector dis(n, vector<int>(n));
    vector dx = {0, 0, -1, 1};
    vector dy = {-1, 1, 0, 0};
    for (int i = 0; i < n; i++) {
        queue<pair<int, int>> q;
        vector d(H, vector(W, -1));
        q.push(p[i]);
        d[p[i].first][p[i].second] = 0;
        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k], ny = y + dy[k];
                if (nx >= 0 && nx < H && ny >= 0 && ny < W && A[nx][ny] != '#' && d[nx][ny] == -1) {
                    d[nx][ny] = d[x][y] + 1;
                    q.emplace(nx, ny);
                }
            }
        }
        for (int j = 0; j < n; j++) {
            dis[i][j] = d[p[j].first][p[j].second];
        }
    }
    vector dp(1 << n, vector(n, T + 1));
    dp[1][0] = 0;
    int res = -1;
    for (int s = 1; s < (1 << n); s++) {
        if (dp[s][n - 1] <= T) {
            res = max(res, __builtin_popcount(s) - 2);
        }
        for (int u = 0; u < n; u++) {
            if (s >> u & 1) {
                for (int v = 0; v < n; v++) {
                    if (!(s >> v & 1) && dis[u][v] != -1) {
                        dp[s | (1 << v)][v] = min(dp[s | (1 << v)][v], dp[s][u] + dis[u][v]);
                    }
                }
            }
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