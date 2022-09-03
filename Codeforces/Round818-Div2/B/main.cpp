#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, k, r, c;
    cin >> n >> k >> r >> c;
    r--; c--;
    vector<string> cell(3 * n, string(n, '.'));
    vector<int> dx = {-1, 1};
    vector<int> dy = {1, -1};
    for (int i = n + r; i < 3 * n; i += k) {
        queue<pair<int, int>> q;
        q.push({i, c});
        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            cell[x][y] = 'X';
            for (int k = 0; k < 2; k++) {
                int nx = x + dx[k], ny = y + dy[k];
                if (nx >= 0 && nx < 3 * n && ny >= 0 && ny < 3 * n && cell[nx][ny] == '.') {
                    q.push({nx, ny});
                }
            }
        }
    }
    for (int i = n + r; i >= 0; i -= k) {
        queue<pair<int, int>> q;
        q.push({i, c});
        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            cell[x][y] = 'X';
            for (int k = 0; k < 2; k++) {
                int nx = x + dx[k], ny = y + dy[k];
                if (nx >= 0 && nx < 3 * n && ny >= 0 && ny < 3 * n && cell[nx][ny] == '.') {
                    q.push({nx, ny});
                }
            }
        }
    }
    for (int i = n; i < 2 * n; i++) cout << cell[i] << endl;
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("in.txt", "r", stdin);
#endif
   int ts = 1;
   cin >> ts;
   for (int t = 1; t <= ts; t++) {
       solve();
   }
   return 0;
}

