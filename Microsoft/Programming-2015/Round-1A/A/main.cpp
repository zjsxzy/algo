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

const int MAXN = 5000 + 5;
int n, q;
int color[MAXN], vis[MAXN];
vector<int> adj[MAXN];
void rec(int u) {
	vis[u] = 1;
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (!vis[v]) {
			if (color[u] == color[v]) {
				rec(v);
			}
		}
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int ts;
	scanf("%d", &ts);
	for (int cas = 1; cas <= ts; cas++) {
		printf("Case #%d:\n", cas);
		scanf("%d", &n);
		for (int i = 0; i <= n; i++)
			adj[i].clear();
		for (int i = 0; i < n - 1; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			adj[u].PB(v);
			adj[v].PB(u);
		}
		memset(color, 0, sizeof(color));
		scanf("%d", &q);
		for (int i = 0; i < q; i++) {
			int op;
			scanf("%d", &op);
			if (op == 1) {
				int ret = 0;
				memset(vis, 0, sizeof(vis));
				for (int u = 1; u <= n; u++) {
					if (!vis[u]) {
						rec(u);
						ret++;
					}
				}
				printf("%d\n", ret);
			} else {
				int x, y;
				scanf("%d%d", &x, &y);
				color[x] = y;
			}
		}
	}
	return 0;
}

