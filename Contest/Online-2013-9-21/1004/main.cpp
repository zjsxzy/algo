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
#include <limits.h>
using namespace std;
#define PB push_back
#define MP make_pair
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
#define FOREACH(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
typedef long long LL;

int n;
bool odd;
int col[222];
bool adj[222][222];

void dfs(int u, int c) {
	if (odd) return;
	if (col[u] != -1) {
		if (col[u] != c) {
			odd = true;
		}
		return;
	}
	col[u] = c;
	for (int i = 1; i <= n; i++)
		if (adj[u][i]) {
			dfs(i, 1 - c);
		}
}

int main() {
	while (~scanf("%d", &n)) {
		memset(col, -1, sizeof(col));
		memset(adj, 0, sizeof(adj));
		for (int i = 1; i <= n; i++) {
			int x;
			while (scanf("%d", &x) && x) {
				adj[i][x] = 1;
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				adj[i][j] &= adj[j][i];
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				adj[i][j] = 1 - adj[i][j];
			}
			adj[i][i] = 0;
		}
		if (n == 2) {
			puts("YES");
			continue;
		}
		odd = false;
		for (int i = 1; i <= n; i++) {
			if (col[i] == -1) {
				dfs(i, 0);
			}
		}
		if (odd) {
			puts("NO");
		} else {
			puts("YES");
		}
	}
	return 0;
}
