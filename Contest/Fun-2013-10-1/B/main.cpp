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

const int MOD = 100000;
struct Restrict {
	int x1, y1, x2, y2;
}re[105];
int n, m;
bool forbid[16][16][16][16];
int dp[16][16][16][16];

int main() {
	int Test;
	scanf("%d", &Test);
	for (int cas = 1; cas <= Test; cas++) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < m; i++) {
			scanf("%d%d%d%d", &re[i].x1, &re[i].y1, &re[i].x2, &re[i].y2);
		}
		memset(forbid, 0, sizeof(forbid));
		memset(dp, 0, sizeof(dp));

		int i[5];
		for (i[1] = 0; i[1] <= n; i[1]++)
			for (i[2] = 0; i[2] <= n; i[2]++)
				for (i[3] = 0; i[3] <= n; i[3]++)
					for (i[4] = 0; i[4] <= n; i[4]++)
						for (int j = 0; j < m; j++) {
							if ((i[re[j].x1] < re[j].y1) != (i[re[j].x2] < re[j].y2)) {
								forbid[i[1]][i[2]][i[3]][i[4]] = true;
								break;
							}
						}

		dp[0][0][0][0] = 1;
		for (int c = 1; c <= 256; c++) {
			for (int col = 1; col <= 4; col++)
				for (i[1] = 0; i[1] <= n; i[1]++)
					for (i[2] = 0; i[2] <= n; i[2]++)
						for (i[3] = 0; i[3] <= n; i[3]++)
							for (i[4] = 0; i[4] <= n; i[4]++) {
								if (i[col]) {
									int temp = dp[i[1]][i[2]][i[3]][i[4]];
									i[col]--;
									temp += dp[i[1]][i[2]][i[3]][i[4]];
									i[col]++;
									if (temp >= MOD) temp -= MOD;
									dp[i[1]][i[2]][i[3]][i[4]] = temp;
								}
							}

			for (i[1] = 0; i[1] <= n; i[1]++)
				for (i[2] = 0; i[2] <= n; i[2]++)
					for (i[3] = 0; i[3] <= n; i[3]++)
						for (i[4] = 0; i[4] <= n; i[4]++)
							if (forbid[i[1]][i[2]][i[3]][i[4]])
								dp[i[1]][i[2]][i[3]][i[4]] = 0;
		}
		printf("Case %d: %05d\n", cas, dp[n][n][n][n]);
	}
	return 0;
}
