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

const int MAXN = 300000 + 5;
int n, m;
vector<pair<int, int> > edge[MAXN];
int dp[MAXN], tmp[MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in3.txt", "r", stdin);
#endif
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		edge[w].PB(MP(u, v));
	}
	for (int i = 0; i < MAXN; i++) {
		for (int j = 0; j < edge[i].size(); j++) {
			int u = edge[i][j].first, v = edge[i][j].second;
			tmp[v] = 0;
		}
		for (int j = 0; j < edge[i].size(); j++) {
			int u = edge[i][j].first, v = edge[i][j].second;
			tmp[v] = max(tmp[v], dp[u] + 1);
		}
		for (int j = 0; j < edge[i].size(); j++) {
			int u = edge[i][j].first, v = edge[i][j].second;
			dp[v] = max(dp[v], tmp[v]);
		}
	}
	int ret = 0;
	for (int i = 1; i <= n; i++)
		ret = max(ret, dp[i]);
	printf("%d\n", ret);
	return 0;
}