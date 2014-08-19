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

const int maxn = 55;
const int dx[8] = {0, 0, 1, 1, -1, -1, -1, 1};
const int dy[8] = {1, -1, -1, 1, 1, -1, 0, 0};
char mat[maxn][maxn];
int dis[maxn][maxn][2];
int n, m;
int sx, sy, tx, ty;

bool legel(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m && mat[x][y] != 'X';
}

bool cross(int x, int y) {
	return tx == x && y >= ty;
}

int main() {
	while (~scanf("%d%d", &n, &m)) {
		for (int i = 0; i < n; i++) {
			scanf("%s", mat[i]);
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (mat[i][j] == '*') {
					sx = i; sy = j;
				}
				if (mat[i][j] == 'X') {
					tx = i; ty = j;
				}
			}
		}

		memset(dis, -1, sizeof(dis));
		queue<pair<pair<int, int>, int> > q;
		q.push(MP(MP(sx, sy), 0));
		dis[sx][sy][0] = 0;
		while (!q.empty()) {
			int curx = q.front().first.first;
			int cury = q.front().first.second;
			int state = q.front().second;
			q.pop();

			for (int k = 0; k < 8; k++) {
				int nxtx = curx + dx[k];
				int nxty = cury + dy[k];
				int nxts = state;
				if (state == 0 && cross(curx, cury) && dx[k] > 0) {
					nxts = 1;
				}

				if (!legel(nxtx, nxty)) continue;
				if (cross(nxtx, nxty) && dx[k] < 0) continue;
				if (dis[nxtx][nxty][nxts] >= 0) continue;
				dis[nxtx][nxty][nxts] = dis[curx][cury][state] + 1;
				q.push(MP(MP(nxtx, nxty), nxts));
			}
		}
		cout << dis[sx][sy][1] << endl;
	}
	return 0;
}
