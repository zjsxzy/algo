#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
#define MP(a, b) make_pair(a, b)
#define FOREACH(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)

const int maxn = 200, half = maxn >> 1;
const int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int maze[maxn][maxn], isPrime[maxn][maxn];
int px[maxn * maxn + 1], py[maxn * maxn + 1];  

int isPrimeFunc(int x) {
	if (x == 1)
		return 0;
	for (int p = 2; p * p <= x; p++)
		if (x % p == 0)
			return 0;
	return 1;
}

int valid(int x, int y) {
	if (x < 0 || x >= maxn || y < 0 || y >= maxn)
		return 0;
	if (isPrime[x][y])
		return 0;
	return 1;
}

void Put(int x, int y, int v) {
	maze[x][y] = v;
	isPrime[x][y] = isPrimeFunc(v);
	px[v] = x;
	py[v] = y;
}

void prepare() {
	for (int i = 0; i < half; i++) {
		int x = half - i - 1, y = half - i - 1;
		int cur = i * i * 4;
		for (int j = 0; j < 2 * i + 1; j++) {
			x++;
			cur++;
			Put(x, y, cur);
		}
		for (int j = 0; j < 2 * i + 1; j++) {
			y++;
			cur++;
			Put(x, y, cur);
		}
		for (int j = 0; j < 2 * i + 1; j++) {
			x--;
			cur++;
			Put(x, y, cur);
		}
		for (int j = 0; j < 2 * i + 1; j++) {
			y--;
			cur++;
			Put(x, y, cur);
		}
	}
}

int dis[maxn][maxn];
queue<PII > Q;
int BFS(int sx, int sy, int dx, int dy) {
	while (Q.size()) Q.pop();
	if (sx == dx && sy == dy)
		return 0;
	memset(dis, -1, sizeof(dis));
	Q.push(MP(sx, sy));
	dis[sx][sy] = 0;
	while (Q.size()) {
		PII node = Q.front();	Q.pop();
		int cx = node.first;
		int cy = node.second;
		int ndis = dis[cx][cy] + 1;
		for (int i = 0; i < 4; i++) {
			int nx = cx + dir[i][0];
			int ny = cy + dir[i][1];
			if (!valid(nx, ny))
				continue;
			if (nx == dx && ny == dy)
				return ndis;
			if (dis[nx][ny] == -1) {
				dis[nx][ny] = ndis;
				Q.push(MP(nx, ny));
			}
		}
	}
	return -1;
}

int main() {
	prepare();
//	for (int i = 0; i < maxn; i++)
//	for (int j = 0; j < maxn; j++) {
//		printf("%d%c", maze[i][j], '\t');
//		if (j == maxn - 1)
//			puts("");
//	}
	int src, des;
	for (int tid = 1; ~scanf("%d %d", &src, &des); tid++) {
		int nsrc = px[src] * maxn + py[src];	
		int ndes = px[des] * maxn + py[des];	

		int res = BFS(px[src], py[src], px[des], py[des]);

		printf("Case %d: ", tid);
		if (res == -1) puts("impossible");
		else printf("%d\n", res);
	}
	return 0;
}