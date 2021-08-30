/*
ID: frankzh1
TASK: camelot
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int MAXN = 55;
const int INF = 1e6;
const int dx[8] = {-1, 1, 2, 2, 1, -1, -2, -2};
const int dy[8] = {2, 2, 1, -1, -2, -2, -1, 1};
int r, c, kingx, kingy;
int mat[MAXN][MAXN];
int dis[MAXN][MAXN][2];
bool vis[MAXN][MAXN][2];
struct node {
    int x, y, king;
    node() {}
    node(int x, int y, int king) {
        this->x = x;
        this->y = y;
        this->king = king;
    }
};

bool operator< (node a, node b) {
	return a.x < b.x;
}

bool inside(int x, int y) {
    return x >= 1 && x <= r && y >= 1 && y <= c;
}

int dijkstra(int stx, int sty) {
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            dis[i][j][0] = dis[i][j][1] = INF;
        }
    }
    memset(vis, 0, sizeof(vis));
    priority_queue<pair<int, node>, vector<pair<int, node>>, greater<pair<int, node>>> pq;
    dis[stx][sty][0] = 0;
    node st(stx, sty, 0);
    pq.push({0, st});
    while (!pq.empty()) {
        auto t = pq.top(); pq.pop();
        int d = t.first;
        node now = t.second;
        if (vis[now.x][now.y][now.king]) continue;
        vis[now.x][now.y][now.king] = true;
        for (int k = 0; k < 8; k++) {
            node nxt;
            nxt.x = now.x + dx[k];
            nxt.y = now.y + dy[k];
            nxt.king = now.king;
            if (inside(nxt.x, nxt.y) && d + 1 < dis[nxt.x][nxt.y][nxt.king]) {
                dis[nxt.x][nxt.y][nxt.king] = d + 1;
                pq.push({d + 1, nxt});
            }
        }
        if (!now.king) {
            int d1 = dis[now.x][now.y][0] + max(abs(kingx - now.x), abs(kingy - now.y));
            int d2 = dis[now.x][now.y][1];
            dis[now.x][now.y][1] = min(d1, d2);
            now.king = 1;
            pq.push({dis[now.x][now.y][1], now});
        }
    }
    int sum = 0;
    for (int x = 1; x <= r; x++) {
        for (int y = 1; y <= c; y++) {
            if (mat[x][y]) {
                if (dis[x][y][0] == INF) return INF;
                sum += dis[x][y][0];
            }
        }
    }
    int res = sum + max(abs(stx - kingx), abs(sty - kingy));
    for (int x = 1; x <= r; x++) {
        for (int y = 1; y <= c; y++) {
            if (mat[x][y]) {
                res = min(res, sum + dis[x][y][1] - dis[x][y][0]);
            }
        }
    }
    return res;
}

void solve() {
    cin >> r >> c;
    char y;
    int x;
    cin >> y >> x;
    kingx = x;
    kingy = y - 'A' + 1;
    while (cin >> y >> x) {
        mat[x][y - 'A' + 1] = 1;
    }
    int res = INF;
    for (int x = 1; x <= r; x++) {
        for (int y = 1; y <= c; y++) {
            int dist = dijkstra(x, y);
            res = min(res, dist);
        }
    }
    if (res == INF) cout << 0 << endl;
    else cout << res << endl;
}

int main() {
    freopen("camelot.in", "r", stdin);
    freopen("camelot.out", "w", stdout);
    solve();
    return 0;
}

