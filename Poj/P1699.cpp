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

const int maxn = 12;
const int inf = 1 << 30;
char str[maxn][25];
int n;
int len[maxn];
int cost[maxn][maxn];
int dp[1 << maxn][maxn];

void ExtendedKMP(char a[], char b[], int M, int N, int nxt[], int ret[]) {
	int i, j, k;
	for (j = 0; 1 + j < M && a[j] == a[1 + j]; j++);
	nxt[1] = j;
	k = 1;
	for (i = 2; i < M; i++) {
		int len = k + nxt[k], L = nxt[i - k];
		if (L < len - i) {
			nxt[i] = L;
		} else {
			for (j = max(0, len - i); i + j < M && a[j] == a[i + j]; j++);
			nxt[i] = j;
			k = i;
		}
	}
	for (j = 0; j < N && j < M && a[j] == b[j]; j++);
	ret[0] = j;
	k = 0;
	for (i = 1; i < N; i++) {
		int len = k + ret[k], L = nxt[i - k];
		if (L < len - i) {
			ret[i] = L;
		} else {
			for (j = max(0, len - i); j < M && i + j < N && a[j] == b[i + j]; j++);
			ret[i] = j;
			k = i;
		}
	}
}

int main() {
	int Test;
	scanf("%d", &Test);
	while (Test--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%s", str[i]);
			len[i] = strlen(str[i]);
		}
		memset(cost, 0, sizeof(cost));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j) continue;
				int nxt[25] = {0}, ret[25] = {0};
				ExtendedKMP(str[i], str[j], len[i], len[j], nxt, ret);
				for (int k = 0; k < len[j]; k++)
					if (ret[k] == len[j] - k)
						cost[j][i] = max(cost[j][i], ret[k]);
			}
		}

		for (int mask = 0; mask < (1 << n); mask++)
			for (int i = 0; i < n; i++)
				dp[mask][i] = inf;
		for (int i = 0; i < n; i++)
			dp[1 << i][i] = len[i];

		for (int mask = 0; mask < (1 << n); mask++) {
			for (int i = 0; i < n; i++) {
				if (!(mask & (1 << i))) continue;
				for (int j = 0; j < n; j++)
					if (!(mask & (1 << j))) {
						int newmask = mask | (1 << j);
						int temp = dp[mask][i] + len[j] - cost[i][j];
						if (temp < dp[newmask][j])
							dp[newmask][j] = temp;
					}
				}
		}
		int res = inf;
		for (int i = 0; i < n; i++)
			if (dp[(1 << n) - 1][i] < res)
				res = dp[(1 << n) - 1][i];
		printf("%d\n", res);
	}
	return 0;
}
