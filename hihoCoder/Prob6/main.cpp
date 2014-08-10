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

const int MAXN = 500 + 5;
const int MAXM = 100000 + 5;
int n, m;
int need[MAXN], value[MAXN];
int dp[MAXM];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &need[i], &value[i]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = m; j >= need[i]; j--) {
			dp[j] = max(dp[j], dp[j - need[i]] + value[i]);
		}
	}
	printf("%d\n", dp[m]);
	return 0;
}

