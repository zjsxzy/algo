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

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};
int n, cnt;
char mat[22][22];

bool check(int i, int j) {
	return (i >= 0 && i < n && j >= 0 && j < n && mat[i][j] == '#');
}

void dfs(int i, int j) {
	mat[i][j] = '.';
	cnt++;
	for (int k = 0; k < 4; k++)
		if (check(i + dx[k], j + dy[k])) {
			dfs(i + dx[k], j + dy[k]);
		}
}

int main() {
	int ts;
	scanf("%d", &ts);
	for (int cas = 1; cas <= ts; cas++) {
		printf("Case #%d: ", cas);
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%s", mat[i]);
		bool square = true, first = false;
		for (int i = 0; i < n && square; i++) {
			for (int j = 0; j < n && square; j++) {
				if (mat[i][j] == '#') {
					if (first) {
						square = false;
						break;
					}
					first = true;
					int w = 0, h = 0;
					for (; mat[i][j + w] == '#' && j + w < n; w++);
					for (; mat[i + h][j] == '#' && i + h < n; h++);
					if (w != h) {
						square = false;
						break;
					}
					cnt = 0;
					dfs(i, j);
					if (cnt != w * h) {
						square = false;
						break;
					}
				}
			}
		}
		if (square) puts("YES");
		else puts("NO");
	}
	return 0;
}

