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

const int maxn = 100 + 5;
const int maxS = 200000 + 5;
const int BASE = 100000;
int n, k;
int a[maxn], b[maxn];
int dp[2][maxS];

int main() {
	cin >> n >> k;
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
		b[i] = a[i] - k * b[i];
	}
	
	memset(dp, -1, sizeof(dp));
	dp[0][BASE] = 0;
	int cur = 0, nxt = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= (BASE << 1); j++)
			dp[nxt][j] = -1;
		for (int j = 0; j <= (BASE << 1); j++) {
			if (dp[cur][j] == -1) continue;
			dp[nxt][j] = max(dp[nxt][j], dp[cur][j]);
			int newj = j + b[i];
			if (newj >= 0 && newj <= (BASE << 1)) {
				dp[nxt][newj] = max(dp[nxt][newj], dp[cur][j] + a[i]);
			}
		}
		cur ^= 1; nxt ^= 1;
	}
	printf("%d\n", dp[cur][BASE] == 0 ? -1 : dp[cur][BASE]);
	return 0;
}

