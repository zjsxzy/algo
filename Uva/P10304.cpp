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

const int MAXN = 255;
int n;
int freq[MAXN], sum[MAXN], dp[MAXN][MAXN];
int rec(int l, int r) {
	if (dp[l][r] != -1) return dp[l][r];
	if (l >= r) return dp[l][r] = 0;
	int res = INT_MAX;
	for (int k = l; k <= r; k++) {
		res = min(res, rec(l, k - 1) + rec(k + 1, r) + sum[r] - sum[l - 1] - freq[k]);
	}
	// cout << l << " " << r << " " << res << endl;
	return dp[l][r] = res;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	while (~scanf("%d", &n)) {
		memset(dp, -1, sizeof(dp));
		sum[0] = 1;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &freq[i]);
			sum[i] = sum[i - 1] + freq[i];
		}
		int res = rec(1, n);
		printf("%d\n", res);
	}
	return 0;
}

