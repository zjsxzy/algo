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

const int MAXN = 200;
int mat[205][205];
bool isprime[205][205];
bool prime[MAXN * MAXN + 5];
int px[MAXN * MAXN + 5], py[MAXN * MAXN + 5];
int dis[205][205];

void getPrime() {
	prime[1] = false;
	for (int i = 2; i <= MAXN * MAXN; i++)
		prime[i] = true;
	for (int i = 2; i <= MAXN * MAXN; i++) {
		if (prime[i]) {
			for (int j = 2; j * i <= MAXN * MAXN; j++)
				prime[j * i] = false;
		}
	}
}

void put(int num, int x, int y) {
	if (prime[num]) {
		isprime[x][y] = true;
	}
	px[num] = x;
	py[num] = y;
	mat[x][y] = num;
}

void make() {
	memset(mat, 0, sizeof(mat));
	int curx = (MAXN + 2) >> 1, cury = (MAXN + 1) >> 1;
	int dir = 0; // 0: right, 1: up, 2: left, 3: down
	int tot = 0;
	int cnt = 2;
	int pt = 0;
	for (int i = 1; i <= MAXN * MAXN; i++) {
		put(i, curx, cury);
		pt++;
		if (pt == cnt) {
			tot++;
			pt = 1;
			dir = (dir + 1) % 4;
		}
		if (tot == 2) {
			cnt++;
			tot = 0;
		}
		if (dir == 0) {
			cury++;
		} else if (dir == 1) {
			curx--;
		} else if (dir == 2) {
			cury--;
		} else {
			curx++;
		}
	}
}

bool inside(pair<int, int> p) {
	return mat[p.first][p.second] > 0;
}

int bfs(int st, int ed) {
	static int dx[4] = {-1, 1, 0, 0};
	static int dy[4] = {0, 0, -1, 1};
	memset(dis, -1, sizeof(dis));
	int sx = px[st], sy = py[st];
	int ex = px[ed], ey = py[ed];
	dis[sx][sy] = 0;
	queue<pair<int, int> > q;
	q.push(MP(sx, sy));
	while (!q.empty()) {
		pair<int, int> cur = q.front(); q.pop();
		for (int k = 0; k < 4; k++) {
			pair<int, int> nxt(cur.first + dx[k], cur.second + dy[k]);
			if (!inside(nxt)) continue;
			if (isprime[nxt.first][nxt.second]) continue;
			if (dis[nxt.first][nxt.second] != -1) continue;
			dis[nxt.first][nxt.second] = dis[cur.first][cur.second] + 1;
			if (nxt == MP(ex, ey)) return dis[ex][ey];
			q.push(nxt);
		}
	}
	return -1;
}

int main(int argc, char const *argv[])
{
	getPrime();
	make();
	// for (int i = 0; i <= MAXN; i++) {
	// 	for (int j = 0; j <= MAXN; j++) {
	// 		printf("%3d ", mat[i][j]);
	// 	}
	// 	printf("\n");
	// }
	int st, ed;
	for (int cas = 1; ~scanf("%d%d", &st, &ed); cas++) {
		int ret = bfs(st, ed);
		if (ret == -1) printf("Case %d: impossible\n", cas);
		else printf("Case %d: %d\n", cas, ret);
	}
	return 0;
}