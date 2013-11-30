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

const int maxn = 100 + 5;
const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};
int n, m;
char mat[maxn][maxn];
int dp[4][1 << 4];
int d[4][4], dd[4];
int posx[4], posy[4];
int vis[maxn][maxn];
map<pair<int, int>, int> mp;
int K;
int sx, sy;

void bfs(int x, int y, int dis[4]) {
	queue<pair<int, int> > q;
	q.push(MP(x, y));
	memset(vis, -1, sizeof(vis));
	vis[x][y] = 0;
	if (mp.find(MP(x, y)) != mp.end()) {
		dis[mp[MP(x, y)]] = 0;
	}
	while (!q.empty()) {
		int curx = q.front().first;
		int cury = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int xx = curx + dx[k];
			int yy = cury + dy[k];
			if (xx <= 0 || xx > n || yy <= 0 || yy > m) continue;
			if (vis[xx][yy] != -1 || mat[xx][yy] == '#') continue;
			vis[xx][yy] = vis[curx][cury] + 1;
			if (mp.find(MP(xx, yy)) != mp.end()) {
				dis[mp[MP(xx, yy)]] = vis[xx][yy];
			}
			q.push(MP(xx, yy));
		}
	}
}

int dfs(int state, int pos) {
	if (dp[pos][state] != -1) return dp[pos][state];
	if ((state & (1 << pos)) == 0) return 0x3f3f3f3f;
	int ret = 0x3f3f3f3f;
	for (int i = 0; i < K; i++) {
		if (state & (1 << i) && i != pos && d[i][pos] != -1) {
			ret = min(ret, dfs(state - (1 << pos), i) + d[i][pos]);
		}
	}
	return dp[pos][state] = ret;
}

int main() {
	while (~scanf("%d%d", &n, &m)) {
		if (n == 0 && m == 0) break;
		mp.clear();
		memset(d, -1, sizeof(d));
		memset(dd, -1, sizeof(dd));
		for (int i = 1; i <= n; i++) {
			scanf("%s", mat[i] + 1);
			for (int j = 1; j <= m; j++) {
				if (mat[i][j] == '@') {
					sx = i, sy = j;
				}
			}
		}
		scanf("%d", &K);
		for (int i = 0; i < K; i++) {
			scanf("%d%d", &posx[i], &posy[i]);
			mp[MP(posx[i], posy[i])] = i;
		}
		bfs(sx, sy, dd);
		for (int i = 0; i < K; i++) {
			bfs(posx[i], posy[i], d[i]);
		}
		memset(dp, -1, sizeof(dp));
		for (int i = 0; i < K; i++) {
			dp[i][1 << i] = dd[i];
		}
		int ret = 0x3f3f3f3f;
		for (int i = 0; i < K; i++)
			ret = min(ret, dfs((1 << K) - 1, i));
		printf("%d\n", ret == 0x3f3f3f3f ? -1 : ret);
	}
	return 0;
}

