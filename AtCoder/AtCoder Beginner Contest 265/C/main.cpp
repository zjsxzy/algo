#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (auto& s: grid) cin >> s;
    vector<vector<int>> vst(n, vector<int>(m));
    queue<pair<int, int>> q;
    q.push({0, 0});
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        if (vst[x][y]) {
            cout << -1 << endl;
            return;
        }
        vst[x][y] = true;
        int tx = x, ty = y;
        if (grid[x][y] == 'L') {
            y--;
        } else if (grid[x][y] == 'R') {
            y++;
        } else if (grid[x][y] == 'U') {
            x--;
        } else if (grid[x][y] == 'D') {
            x++;
        }
        if (x < 0 || x >= n || y < 0 || y >= m) {
            cout << tx + 1 << ' ' << ty + 1 << endl;
            return;
        }
        q.push({x, y});
    }
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("in.txt", "r", stdin);
#endif
   int ts = 1;
   // cin >> ts;
   for (int t = 1; t <= ts; t++) {
       solve();
   }
   return 0;
}

