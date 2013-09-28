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
int n, m, p;
int A[maxn][maxn], B[maxn][maxn], C[maxn][maxn];
int x[maxn], e[maxn], f[maxn], g[maxn];

int main() {
	while (~scanf("%d%d%d", &n, &m, &p)) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				scanf("%d", &A[i][j]);
			}
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < p; j++) {
				scanf("%d", &B[i][j]);
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < p; j++) {
				scanf("%d", &C[i][j]);
			}
		}

		for (int i = 0; i < p; i++)
			x[i] = rand();
		for (int i = 0; i < m; i++) {
			e[i] = 0;
			for (int j = 0; j < p; j++)
				e[i] += B[i][j] * x[j];
		}

		bool same = true;
		int pos;
		for (int i = 0; i < n; i++) {
			f[i] = 0;
			for (int j = 0; j < m; j++)
				f[i] += A[i][j] * e[j];
			g[i] = 0;
			for (int j = 0; j < p; j++)
				g[i] += C[i][j] * x[j];	
			if (f[i] != g[i]) {
				same = false;
				pos = i;
				break;
			}
		}
		if (same) {
			puts("Yes");
			continue;
		}
		for (int i = 0; i < p; i++) {
			LL sum = 0;
			for (int j = 0; j < m; j++)
				sum += (LL)A[pos][j] * B[j][i];
			if (sum != C[pos][i]) {
				puts("No");
				printf("%d %d\n", pos + 1, i + 1);
				cout << sum << endl;
			}
		}	
	}	
	return 0;
}
