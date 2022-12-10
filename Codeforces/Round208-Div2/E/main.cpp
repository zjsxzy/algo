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

const int maxn = 1000005;
const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};
int n, m, V, tt;
vector<int> adj[maxn];
int p[maxn];
int mark[1005][1005], idx[1005][1005];
bool vis[1005][1005];
int mat[1005][1005];

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

bool valid(int i, int j) {
	return i >= 1 && i <= n && j >= 1 && j <= m && mat[i][j] == 1;
}

int getid(int i, int j) {
	if (mark[i][j] == tt) return idx[i][j];
	mark[i][j] = tt;
	idx[i][j] = V++;
	adj[V - 1].clear();
	return idx[i][j];
}

void addEdge(int a, int b) {
	adj[a].PB(b);
	adj[b].PB(a);
}

int find(int x) {
	return p[x] == x ? x : p[x] = find(p[x]);
}

bool euler() {
	int odd = 0;
	for (int i = 0; i < V; i++) {
		odd += (adj[i].size() & 1);
	}
	if (odd != 2 && odd != 0) return false;
	for (int i = 0; i < V; i++) p[i] = i;
	for (int i = 0; i < V; i++)
		for (int j = 0; j < adj[i].size(); j++)
			p[find(i)] = find(adj[i][j]);
	for (int i = 0; i < V; i++)
		if (find(i) != find(0)) return false;
	return true;
}

void dfs(int i, int j) {
	vis[i][j] = true;
	for (int k = 0; k < 4; k++) {
		if (valid(i + dx[k], j + dy[k]) && !vis[i + dx[k]][j + dy[k]]) {
			dfs(i + dx[k], j + dy[k]);
		}
	}
}

bool isconnected() {
	bool flag = true;
	memset(vis, 0, sizeof(vis));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (mat[i][j] == 1 && !vis[i][j]) {
				if (!flag) return false;
				dfs(i, j);
				flag = false;
			}
		}
	}
	return true;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &mat[i][j]);
		}
	}
	int g = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; ) {
			for (; j <= m && mat[i][j] == 0; j++);
			if (j == m + 1) break;
			int L = 1;
			for (; j + L <= m && mat[i][j + L] == 1; L++);
			g = gcd(g, L - 1);
			j += L;
		}
	}
	for (int j = 1; j <= m; j++) {
		for (int i = 1; i <= n; ) {
			for (; i <= n && mat[i][j] == 0; i++);
			if (i == n + 1) break;
			int L = 1;
			for (; i + L <= n && mat[i + L][j] == 1; L++);
			g = gcd(g, L - 1);
			i += L;
		}
	}
	if (!isconnected()) {
		puts("-1");
		return 0;
	}
	vector<int> ans;
	tt = 0;
	for (int k = 2; k <= g; k++) if (g % k == 0) {
		V = 0;
		tt++;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				for (; j <= m && mat[i][j] == 0; j++);
				if (j == m + 1) break;
				while (j + 1 <= m && mat[i][j + 1] == 1) {
					addEdge(getid(i, j), getid(i, j + k));
					j += k;
				}
			}
		}
		for (int j = 1; j <= m; j++) {
			for (int i = 1; i <= n; i++) {
				for (; i <= n && mat[i][j] == 0; i++);
				if (i == n + 1) break;
				while (i + 1 <= n && mat[i + 1][j] == 1) {
					addEdge(getid(i, j), getid(i + k, j));
					i += k;
				}
				i++;
			}
		}
		if (euler()) ans.PB(k);
	}
	if (ans.size() == 0) puts("-1");
	else {
		for (int i = 0; i < ans.size(); i++)
			printf("%d%c", ans[i], i == ans.size() - 1 ? '\n' : ' ');
	}
	return 0;
}
