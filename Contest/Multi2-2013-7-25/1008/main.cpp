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

int n, m;
int mat[333][333];
int row[333][333];
int main(int argc, char const *argv[])
{
	int Test;
	scanf("%d", &Test);
	while (Test--) {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				scanf("%d", &mat[i][j]);
			}
		}
		int ret = 0;

		//Situation 1
		memset(row, 0, sizeof(row));
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				int k = 0;
				for (; j - k >= 1 && j + k <= m && mat[i][j - k] == mat[i][j + k]; k++);
				row[i][j] = 2 * k - 1;
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				int k = 0;
				int temp = row[i][j];
				for (; i - k >= 1 && i + k <= n && mat[i - k][j] == mat[i + k][j]; ) {
					if (min(2 * k + 1, temp) > ret) {
						ret = min(2 * k + 1, temp);
					}
					temp = min(temp, row[i - k][j]);
					temp = min(temp, row[i + k][j]);
					k++;
				}
				if (i + 1 <= n && mat[i][j] == mat[i + 1][j]) {
					k = 0;
					temp = min(row[i][j], row[i + 1][j]);
					for (; i - k >= 1 && i + 1 + k <= n && mat[i - k][j] == mat[i + 1 + k][j]; ) {
						if (min(2 * k + 2, temp) > ret) {
							ret = min(2 * k + 2, temp);
						}
						temp = min(temp, row[i - k][j]);
						temp = min(temp, row[i + 1 + k][j]);
						k++;
					}
				}
			}
		}

		//Situation 2
		memset(row, 0, sizeof(row));
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (j + 1 <= m && mat[i][j] == mat[i][j + 1]) {
					int k = 0;
					for (; j - k >= 1 && j + 1 + k <= m && mat[i][j - k] == mat[i][j + 1 + k]; k++);
					row[i][j] = max(row[i][j], 2 * k);
					row[i][j + 1] = max(row[i][j + 1], 2 * k);
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (j + 1 <= m && mat[i][j] == mat[i][j + 1]) {
					int k = 0;
					int temp = row[i][j];
					for (; i - k >= 1 && i + k <= n && mat[i - k][j] == mat[i + k][j] && mat[i - k][j + 1] == mat[i + k][j]; ) {
						if (min(2 * k + 1, temp) > ret) {
							ret = min(2 * k + 1, temp);
						}
						temp = min(temp, row[i - k][j]);
						temp = min(temp, row[i + k][j]);
						k++;
					}
					if (i + 1 <= n && mat[i][j] == mat[i + 1][j]) {
						k = 0;
						temp = min(row[i][j], row[i + 1][j]);
						for (; i - k >= 1 && i + 1 + k <= n && mat[i - k][j] == mat[i + 1 + k][j] && mat[i - k][j + 1] == mat[i + 1 + k][j]; ) {
							if (min(2 * k + 2, temp) > ret) {
								ret = min(2 * k + 2, temp);
							}
							temp = min(temp, row[i - k][j]);
							temp = min(temp, row[i + 1 + k][j]);
							k++;
						}
					}
				}
			}
		}
		printf("%d\n", ret);
	}
	return 0;
}