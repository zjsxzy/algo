#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
#define MP(a, b) make_pair(a, b)
#define FOREACH(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#pragma comment(linker, "/STACK:1024000000,1024000000")

const int maxm = 10, INF = 0x3f3f3f3f;
int bit[maxm], ship[maxm];
int dp[1 << maxm][1 << maxm][maxm][maxm];

int isValidStatus(int hit, int mis, int m, int w) {
	for (int i = 0; i <= m - w; i++) {
		int curShip = ship[w] << i;
		if (((curShip | hit) == curShip) && ((curShip & mis) == 0))
			return 1;
	}
	return 0;
}

// 1 * m
int rec(int hit, int mis, int m, int w, int hitCnt) {
	if (dp[hit][mis][m][w] != INF)
		return dp[hit][mis][m][w];
	if (w == hitCnt) {
		return 0;
	}
	int res = INF;
	for (int i = 0; i < m; i++)
	if (!(hit & bit[i]) && !(mis & bit[i])){
		int tmp1 = -1, tmp2 = -1;
		int nHit = hit | bit[i];
		int nMis = mis | bit[i];
		if (isValidStatus(nHit, mis, m, w))
			tmp1 = rec(nHit, mis, m, w, hitCnt + 1);
		if (isValidStatus(hit, nMis, m, w))
			tmp2 = rec(hit, nMis, m, w, hitCnt);
		int tmp = max(tmp1, tmp2);
		res = min(res, tmp);
	}
	if (res != -1)
		res++;
	dp[hit][mis][m][w] = res;
	return res;
}

void init() {
	for (int m = 0; m < maxm; m++) bit[m] = 1 << m;
	for (int w = 1; w < maxm; w++) {
		ship[w] = 0;
		for (int i = 0; i < w; i++)
			ship[w] |= bit[i];
	}
	memset(dp, 0x3f, sizeof(dp));
}

int main() {
	init();
	int test;	scanf("%d", &test);
	int n, m, w;
	for (int ti = 1; ti <= test; ti++) {
		scanf("%d %d %d", &n, &m, &w);
		int res = rec(0, 0, m, w, 0);
		printf("Case #%d: %d\n", ti, res);
	}
	return 0;
}
