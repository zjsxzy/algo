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
int best[2][MAXM];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d%d", need + i, value + i);

	int pre = 0, cur = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			best[cur][j] = 0;
		}
		for (int j = 0; j <= m; j++) {
			if (need[i] > j) {
				best[cur][j] = best[pre][j];
			} else {
				best[cur][j] = max(best[pre][j], best[cur][j - need[i]] + value[i]);
			}
		}
		pre ^= 1; cur ^= 1;
	}
	printf("%d\n", best[pre][m]);
	return 0;
}

