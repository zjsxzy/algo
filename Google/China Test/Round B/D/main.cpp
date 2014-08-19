#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <bitset>
#include <vector>
#include <cstdio>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define PB push_back
#define MP make_pair
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
#define FOREACH(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
typedef long long LL;

const int maxn = 105;
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {-1, 1, 0, 0};
int n, m;
int sx, sy, ex, ey;
int maze[maxn][maxn], d[maxn][maxn];
int f[maxn][maxn];

bool valid(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m && maze[x][y] != -1;
}

void bfs() {
	memset(d, -1, sizeof(d));
	d[sx][sy] = 0;
	f[sx][sy] = maze[sx][sy];
	queue<pair<int, int> > q;
	q.push(MP(sx, sy));
	while (!q.empty()) {
		pair<int, int> cur = q.front(); q.pop();
		for (int k = 0; k < 4; k++) {
			int x = cur.first + dx[k], y = cur.second + dy[k];
			if (valid(x, y)) {
				if (d[x][y] == -1) {
					d[x][y] = d[cur.first][cur.second] + 1;
					f[x][y] = f[cur.first][cur.second] + maze[x][y];
					q.push(MP(x, y));
				} else if (d[cur.first][cur.second] + 1 == d[x][y]) {
					if (f[cur.first][cur.second] + maze[x][y] > f[x][y]) {
						f[x][y] = f[cur.first][cur.second] + maze[x][y];
						q.push(MP(x, y));
					}
				}
			}
		}
	}
}

void work() {
	cin >> n >> m;
	cin >> sx >> sy >> ex >> ey;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> maze[i][j];
		}
	}
	if (maze[sx][sy] == -1 || maze[ex][ey] == -1) {
		cout << "Mission Impossible" << endl;
		return;
	}
	bfs();
	if (d[ex][ey] == -1) cout << "Mission Impossible." << endl;
	else {
		cout << f[ex][ey] << endl;
	}
}

int main() {
	int Test;
	cin >> Test;
	for (int cas = 1; cas <= Test; cas++) {
		printf("Case #%d: ", cas);
		work();
	}
	return 0;
}
