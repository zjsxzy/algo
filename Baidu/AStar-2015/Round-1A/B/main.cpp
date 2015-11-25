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
#include <cassert>
#include <climits>
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

const int MAXN = 1000 + 5;
const int inf = 1000000000;
const int dx[] = {0, 0, -1, 1};
const int dy[] = {1, -1, 0, 0};
int n, m;
int h[MAXN][MAXN], dis[MAXN][MAXN];
bool vst[MAXN][MAXN];
bool valid(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m && vst[x][y] == false;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int ts;
	scanf("%d", &ts);
	for (int cas = 1; cas <= ts; cas++) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				scanf("%d", &h[i][j]);
				dis[i][j] = inf;
				vst[i][j] = false;
			}
		}
		dis[0][0] = 0;
		priority_queue<pair<int, pair<int, int> > > pq;
		pq.push(MP(0, MP(0, 0)));
		LL res = 0;
		while (!pq.empty()) {
			pair<int, int> curr = pq.top().second;
			int d = -pq.top().first;
			pq.pop();
			if (vst[curr.first][curr.second]) continue;
			vst[curr.first][curr.second] = true;
			res += d;
			// cout << curr.first << " " << curr.second << " " << d << endl;
			for (int k = 0; k < 4; k++) {
				int x = curr.first + dx[k], y = curr.second + dy[k];
				if (!valid(x, y)) continue;
				int temp = abs(h[x][y] - h[curr.first][curr.second]);
				if (!vst[x][y] && temp < dis[x][y]) {
					dis[x][y] = temp;
					pq.push(MP(-temp, MP(x, y)));
				}
			}
		}
		printf("Case %d:\n",cas);
		cout << res << endl;
	}
	return 0;
}

