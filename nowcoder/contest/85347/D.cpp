#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int d[11][11][10005];

void solve() {
    int n, m, p;
    cin >> n >> m >> p;
    p--;
    vector a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    vector b(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> b[i][j];
        }
    }
    const int inf = 1e9;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < p; k++) {
                d[i][j][k] = inf;
            }
        }
    }
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    d[0][0][a[0][0] % p] = 0;
    queue<pair<pair<int, int>, int> > q;
    q.push({{0, 0}, a[0][0] % p});
    while (!q.empty()) {
        auto t = q.front(); q.pop();
        int x = t.first.first, y = t.first.second, z = t.second;
        // cout << x << ' ' << y << ' ' << z << ' ' << d[x][y][z] << endl;
        if (x == n - 1 && y == m - 1 && z == 0) {
            cout << d[x][y][z] << endl;
            return;
        }
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && d[x][y][z] + 1 < d[nx][ny][(z + a[nx][ny]) % p]) {
                d[nx][ny][(z + a[nx][ny]) % p] = d[x][y][z] + 1;
                q.push({{nx, ny}, (z + a[nx][ny]) % p});
            }
        }
    }
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