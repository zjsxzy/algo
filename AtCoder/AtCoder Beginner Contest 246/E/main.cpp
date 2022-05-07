#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 1505;
int dx[4] = {1, -1, 1, -1};
int dy[4] = {-1, 1, 1, -1};
int dist[maxn][maxn][4];
string s[maxn];
int n, ax, ay, bx, by;

void solve() {
    cin >> n >> ax >> ay >> bx >> by;
    ax--; ay--; bx--; by--;
    for (int i = 0; i < n; i++) cin >> s[i];
    memset(dist, 0x3f, sizeof(dist));
    deque<array<int, 4>> que;
    for (int d = 0; d < 4; d++) {
        que.push_back({ax, ay, d, 1});
        dist[ax][ay][d] = 1;
    }
    while (!que.empty()) {
        auto curr = que.front(); que.pop_front();
        if (curr[3] != dist[curr[0]][curr[1]][curr[2]]) continue;
        if (curr[0] == bx && curr[1] == by) {
            cout << curr[3] << endl;
            return;
        }
        for (int d = 0; d < 4; d++) {
            int x = curr[0] + dx[d], y = curr[1] + dy[d];
            if (x >= 0 && x < n && y >= 0 && y < n && s[x][y] == '.') {
                int t = curr[3] + (curr[2] != d);
                if (t < dist[x][y][d]) {
                    dist[x][y][d] = t;
                    if (d == curr[2]) que.push_front({x, y, d, t});
                    else que.push_back({x, y, d, t});
                }
            }
        }
    }
    cout << -1 << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

