#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int inf = 10000000;
int dx[8] = {0, 0, -1, 1, 1, -1, -1, 1};
int dy[8] = {-1, 1, 0, 0, 1, -1, 1, -1};
int n;
string grid[2];
int dist[2][105];

bool inside(int x, int y) {
    return x >= 0 && x < 2 && y >= 0 && y < n;
}

void solve() {
    cin >> n;
    for (int i = 0; i < 2; i++) {
        cin >> grid[i];
    }
    for (int i = 0; i < n; i++) {
        dist[0][i] = dist[1][i] = inf;
    }
    queue<pair<int, int>> q;
    dist[0][0] = 0;
    q.push({0, 0});
    while (!q.empty()) {
        auto t = q.front(); q.pop();
        for (int k = 0; k < 8; k++) {
            int x = t.first + dx[k], y = t.second + dy[k];
            if (inside(x, y) && grid[x][y] == '0' && dist[x][y] == inf) {
                dist[x][y] = dist[t.first][t.second] + 1;
                q.push({x, y});
            }
        }
    }
    if (dist[1][n - 1] == inf || grid[1][n - 1] == '1') cout << "NO" << endl;
    else cout << "YES" << endl;
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

