#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int dx[4] = {1, -1, 1, -1};
int dy[4] = {-1, 1, 1, -1};
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int sum = grid[i][j];
            for (int d = 0; d < 4; d++) {
                int x = i + dx[d], y = j + dy[d];
                while (x >= 0 && x < n && y >= 0 && y < m) {
                    sum += grid[x][y];
                    x += dx[d];
                    y += dy[d];
                }
            }
            res = max(res, sum);
        }
    }
    cout << res << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int ts;
    cin >> ts;
    while (ts--) {
        solve();
    }
    return 0;
}

