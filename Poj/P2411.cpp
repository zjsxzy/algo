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

int n, m;
const int maxs = 1 << 11;
vector<int> trans[maxs];
LL dp[15][maxs];

void dfs(int dep, int current, int s1, int s2) {
	if (current == (1 << m) - 1) {
		//cout << s1 << " -> " << s2 << endl;
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
	while (~scanf("%d%d", &n, &m)) {
		if (n == 0 && m == 0) break;
		if (m > n) {
			swap(n, m);
		}
		for (int i = 0; i < (1 << m); i++)
			trans[i].clear();
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
				}
			}
		}
		cout << dp[n + 1][0] << endl;
	}
	return 0;
}
