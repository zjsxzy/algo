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

const int maxn = 1005;
int n, m;
int mat[maxn][maxn], sum[maxn][maxn];
int ll[maxn], rr[maxn];

int main() {
	while (~scanf("%d%d", &n, &m)) {
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				scanf("%d", &mat[i][j]);
		for (int j = 1; j <= m; j++) {
			for (int i = 1; i <= n; i++) {
				sum[i][j] = mat[i][j] == 0 ? 0 : sum[i - 1][j] + 1;
			}
		}
		int res = 0;
		for (int i = 1; i <= n; i++) {
			sum[i][0] = -1; sum[i][n + 1] = -1;
			for (int j = 1; j <= m; j++) {
				ll[j] = j;
				while (sum[i][j] <= sum[i][ll[j] - 1])
					ll[j] = ll[ll[j] - 1];
			}
			for (int j = m; j >= 1; j--) {
				rr[j] = j;
				while (sum[i][j] <= sum[i][rr[j] + 1])
					rr[j] = rr[rr[j] + 1];
			}
			for (int j = 1; j <= m; j++) {
				int temp = (rr[j] - ll[j] + 1) * sum[i][j];
				res = max(res, temp);
			}
		}
		printf("%d\n", res);
	}
	return 0;
}
