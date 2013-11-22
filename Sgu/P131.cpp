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
const int maxs = 1 << 9;
int trans[maxs][maxs];
LL dp[2][maxs];

void dfs(int dep, int current, int s1, int s2) {
	if (current >= (1 << m)) return;
	if (current == (1 << m) - 1) {
		//cout << s1 << " -> " << s2 << endl;
		trans[s1][s2]++;
		return;
	}
	if (s1 & (1 << dep)) {
		dfs(dep + 1, current, s1, s2);
	} else {
		// ##
		if (!(s2 & (1 << dep)))
			dfs(dep + 1, current | (1 << dep), s1, s2 | (1 << dep));
		// ##
		//  #
		if (dep + 1 < m && !(s2 & (1 << dep))) {
			dfs(dep + 1, current | (1 << dep), s1, s2 | (1 << dep) | (1 << (dep + 1)));
		}
		//  #
		// ##
		if (dep > 0 && !(s2 & (1 << (dep - 1))) && !(s2 & (1 << dep))) {
			dfs(dep + 1, current | (1 << dep), s1, s2 | (1 << (dep - 1)) | (1 << dep));
		}
		// #
		// #
		if (dep + 1 < m && !(s1 & (1 << (dep + 1)))) {
			dfs(dep + 2, current | (1 << dep) | (1 << (dep + 1)), s1, s2);
		}
		// ##
		// #
		if (dep + 1 < m && !(s1 & (1 << (dep + 1))) && !(s2 & (1 << dep))) {
			dfs(dep + 2, current | (1 << dep) | (1 << (dep + 1)), s1, s2 | (1 << dep));
		}
		// #
		// ##
		if (dep + 1 < m && !(s1 & (1 << (dep + 1)))) {
			dfs(dep + 2, current | (1 << dep) | (1 << (dep + 1)), s1, s2 | (1 << (dep + 1)));
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	if (m > n) {
		swap(n, m);
	}
	for (int i = 0; i < (1 << m); i++)
		dfs(0, i, i, 0);
	
	/*
	for (int i = 0; i < (1 << m); i++) {
		for (int j = 0; j < (1 << m); j++) {
			cout << trans[i][j] << " ";
		}
		cout << endl;
	}
	*/

	for (int j = 0; j < (1 << m); j++)
		dp[0][j] = 0;
	dp[0][(1 << m) - 1] = 1;
	int cur = 0, nxt = 1;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j < (1 << m); j++)
			dp[nxt][j] = 0;
		for (int j = 0; j < (1 << m); j++) {
			if (dp[cur][j] == 0) continue;
			for (int k = 0; k < (1 << m); k++) {
				dp[nxt][k] += dp[cur][j] * trans[j][k];
			}
		}
		swap(cur, nxt);
	}
	cout << dp[cur][0] << endl;
	return 0;
}
