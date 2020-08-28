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

const int MAXN = 100 + 5;
int n, m;
const int dx[] = {0, -1, 0, 1};
const int dy[] = {-1, 0, 1, 0};
char mat[MAXN][MAXN];
int adj[MAXN][MAXN][4];
bool valid(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}
int main() {
#ifndef ONLINE_JUDGE
//	freopen("in.txt", "r", stdin);
#endif
	int ts; scanf("%d", &ts);
	for (int cas = 1; cas <= ts; cas++) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++) {
			scanf("%s\n", mat[i]);
			// printf("%s\n", mat[i]);
		}
		bool flag = true;
		memset(adj, -1, sizeof(adj));
		for (int i = 0; i < n && flag; i++) {
			for (int j = 0; j < m && flag; j++) {
				if (mat[i][j] != '.') {
					// cout << i << " " << j << endl;
					for (int k = 0; k < 4; k++) {
						int x = i + dx[k], y = j + dy[k];
						while (valid(x, y)) {
							if (mat[x][y] != '.') {
								break;
							}
							x += dx[k];
							y += dy[k];
						}
						if (valid(x, y)) {
							adj[i][j][k] = x * m + y;
						}
					}
					// cout << adj[i][j][3] << endl;
					int temp = 0;
					for (int k = 0; k < 4; k++) {
						if (adj[i][j][k] >= 0) {
							temp = 1;
						}
					}
					if (!temp) {
						flag = false;
					}
				}
			}
		}
		if (!flag) {
			printf("Case #%d: IMPOSSIBLE\n", cas);
		} else {
			int res = 0;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (mat[i][j] != '.') {
						int di = 0;
						if (mat[i][j] == '<')
							di = 0;
						else if (mat[i][j] == '^')
							di = 1;
						else if (mat[i][j] == '>')
							di = 2;
						else di = 3;
						if (adj[i][j][di] == -1)
							res++;
					}
				}
			}
			printf("Case #%d: %d\n", cas, res);
		}
	}
	return 0;
}

