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
int N, M, Q;
int W[MAXN];
int dp[MAXN][1 << 11];

int bitcnt(int x) {
	int ret = 0;
	for (; x; x = x & (x - 1))
		ret++;
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	cin >> N >> M >> Q;
	for (int i = 0; i < N; i++) {
		cin >> W[i];
	}
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < N; i++) {
		for (int mask = 0; mask < (1 << M); mask++) {
			if (dp[i][mask] > dp[i + 1][mask >> 1]) {
				dp[i + 1][mask >> 1] = dp[i][mask];
			}
			int bit = bitcnt(mask);
			if (bit >= Q) continue;
			int newmask = (mask >> 1) | (1 << (M - 2));
			if (dp[i][mask] + W[i] > dp[i + 1][newmask]) {
				dp[i + 1][newmask] = dp[i][mask] + W[i];
			}
		}
	}
	int ret = 0;
	for (int mask = 0; mask < (1 << M); mask++)
		ret = max(ret, dp[N][mask]);
	cout << ret << endl;
	return 0;
}

