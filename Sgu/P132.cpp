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

const int inf = 0x3f3f3f3f;
const int maxn = 75;
const int maxs = 1 << 8;
int dp[2][maxs][maxs];
int state[maxn];
int n, m, initJ, initK, cur, nxt;

void dfs(int dep, int s1, int s2, int current, int cnt) {
	if (dep > 0 && !(s1 & (1 << (dep - 1))) && !(s2 & (1 << (dep - 1)))) {
		return;
	}
	if (dep > 1 && !(s2 & (1 << (dep - 1))) && !(s2 & (1 << (dep - 2)))) {
		return;
	}
	if (dep == m) {
		dp[nxt][s2][current] = min(dp[nxt][s2][current], dp[cur][initJ][initK] + cnt);
		return;
	}

	dfs(dep + 1, s1, s2, current, cnt);
	if (!(s2 & (1 << dep)) && !(current & (1 << dep))) {
		dfs(dep + 1, s1, s2 | (1 << dep), current | (1 << dep), cnt + 1);
	}
	if (dep + 1 < m && !(s2 & (1 << dep)) && !(s2 & (1 << (dep + 1)))) {
		dfs(dep + 1, s1, s2 | (1 << dep) | (1 << (dep + 1)), current, cnt + 1);
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		char str[8];
		scanf("%s", str);
		for (int j = 0; j < m; j++)
			if (str[j] == '*') {
				state[i] |= (1 << j);
			}
	}
	state[n + 1] = 0;

	cur = 0, nxt = 1;
	for (int j = 0; j < (1 << m); j++)
		for (int k = 0; k < (1 << m); k++)
			dp[0][j][k] = inf;
	dp[0][(1 << m) - 1][state[1]] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < (1 << m); j++)
			for (int k = 0; k < (1 << m); k++)
				dp[nxt][j][k] = inf;
		for (int j = 0; j < (1 << m); j++)
			for (int k = 0; k < (1 << m); k++) {
				if (dp[cur][j][k] == inf) continue;
				initJ = j; initK = k;
				dfs(0, j, k, state[i + 1], 0);
			}
		cur ^= 1; nxt ^= 1;
	}
	int res = inf;
	for (int j = 0; j < (1 << m); j++)
		res = min(res, dp[cur][j][0]);
	printf("%d\n", res);
	return 0;
}
