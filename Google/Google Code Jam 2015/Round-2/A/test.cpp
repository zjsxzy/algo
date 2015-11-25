#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
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

const int maxn = 100 + 5;
const int dirx[] = {0, -1, 0, 1};
const int diry[] = {-1, 0, 1, 0};
int n, m, maze[maxn][maxn], adj[maxn][maxn][4];

int isValid(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

int c2Dir(char x) {
	if (x == '.')
		return -1;
	if (x == '<')
		return 0;
	if (x == '^')
		return 1;
	if (x == '>')
		return 2;
	if (x == 'v')
		return 3;
}

char input[100];
int main() {
//freopen("in", "r", stdin);
//freopen("A-small-attempt0.in", "r", stdin);
//freopen("A-small-attempt0.out", "w", stdout);
	int test;	scanf("%d", &test);
	for (int ti = 1; ti <= test; ti++) {
		scanf("%d %d", &n, &m);
		memset(maze, 0, sizeof(maze));
		for (int x = 0; x < n; x++) {
			scanf("%s", input);
			for (int y = 0; y < m; y++)
				maze[x][y] = c2Dir(input[y]);
		}

		int hasRes = 1;
		memset(adj, -1, sizeof(adj));
		for (int x = 0; hasRes && x < n; x++)
		for (int y = 0; hasRes && y < m; y++)
		if (maze[x][y] >= 0) {
			for (int i = 0; i < 4; i++) {
				int curx = x + dirx[i], cury = y + diry[i];
				while (isValid(curx, cury)) {
					if (maze[curx][cury] >= 0)
						break;
					curx += dirx[i];
					cury += diry[i];
				}
				if (isValid(curx, cury))
					adj[x][y][i] = curx * m + cury;
			}
            //cout << adj[x][y][3] << endl;
			int flag = 0;
			for (int i = 0; i < 4; i++)
			if (adj[x][y][i] >= 0) {
                cout << i << endl;
				flag = 1;
            }
			if (!flag) {
				hasRes = 0;
			}
		}

		if (!hasRes) {
			printf("Case #%d: IMPOSSIBLE\n", ti);
		} else {
			int res = 0;
			for (int x = 0; x < n; x++)
			for (int y = 0; y < m; y++)
			if (maze[x][y] >= 0) {
				int di = maze[x][y];
				if (adj[x][y][di] == -1)
					res++;
			}
			printf("Case #%d: %d\n", ti, res);
		}
	}
	return 0;
}
