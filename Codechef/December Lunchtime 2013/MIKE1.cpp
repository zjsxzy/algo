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

const int MAXN = 500 + 5;
int n, m, L;
int mat[MAXN][MAXN];

bool valid(int i, int j) {
	return i >= 1 && i <= n && j >= 1 && j <= m;
}

int main() {
	while (~scanf("%d%d", &n, &m)) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				scanf("%d", &mat[i][j]);
			}
		}
		LL E1 = 0, E2 = 0;
		bool b1 = true, b2 = true;
		scanf("%d", &L);
		for (int k = 1; k <= L; k++) {
			int i, j;
			scanf("%d%d", &i, &j);
			if (!valid(i, j)) b1 = false;
			else E1 += (LL)mat[i][j];
			if (!valid(j, i)) b2 = false;
			else E2 += (LL)mat[j][i];
		}
		if (!b1) E1 = -1;
		if (!b2) E2 = -1;
		cout << max(E1, E2) << endl;
	}
	return 0;
}

