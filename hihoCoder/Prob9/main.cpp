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

const int MAXN = 1005;
const int MAX_MASK = 1 << 5;
const int MOD = 1000000007;
int n, m;
vector<int> trans[MAX_MASK];
LL dp[MAXN][MAX_MASK];

void dfs(int dep, int current, int s1, int s2) {
	if (current == (1 << m) - 1) {
		trans[s1].PB(s2);
		return;
	}
	if (s1 & (1 << dep)) {
		dfs(dep + 1, current, s1, s2);
	} else {
		dfs(dep + 1, current | (1 << dep), s1, s2 | (1 << dep));
		if (dep + 1 < m && !(s1 & (1 << (dep + 1)))) {
			dfs(dep + 2, current | (1 << dep) | (1 << (dep + 1)), s1, s2);
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	scanf("%d%d", &n, &m);
	for (int i = 0; i < (1 << m); i++)
		dfs(0, i, i, 0);
	memset(dp, 0, sizeof(dp));
	dp[0][(1 << m) - 1] = 1;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j < (1 << m); j++) {
			if (dp[i][j] == 0) continue;
			for (int k = 0; k < trans[j].size(); k++) {
				int nxt = trans[j][k];
				dp[i + 1][nxt] += dp[i][j];
				dp[i + 1][nxt] %= MOD;
			}
		}
	}
	cout << dp[n + 1][0] << endl;
	return 0;
}

