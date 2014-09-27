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
int val[MAXN];
int dp[MAXN][MAXN];
vector<int> adj[MAXN];

void dfs(int u, int fa) {
	dp[u][0] = 0;
	dp[u][1] = val[u];
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (v == fa) continue;
		dfs(v, u);
		for (int j = m; j >= 2; j--) {
			for (int k = 1; k < j; k++) {
				dp[u][j] = max(dp[u][j], dp[u][j - k] + dp[v][k]);
			}
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &val[i]);
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		a--; b--;
		adj[a].PB(b);
		adj[b].PB(a);
	}
	dfs(0, -1);
	printf("%d\n", dp[0][m]);
	return 0;
}

