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

const int MAXN = 1000 + 5;
struct Query {
	int l, idx;
	Query() {}
	Query(int l, int idx) : l(l), idx(idx) {}
};
int n, m, K;
bool forbid[MAXN][MAXN];
vector<Query> query[MAXN];

int main() {
	while (~scanf("%d%d%d", &n, &m, &K)) {
		memset(forbid, 0, sizeof(forbid));
		for (int i = 0; i < K; i++) {
			int x, y;
			scanf("%d%d", &x, &y);
			forbid[x][y] = 1;
		}
		for (int x = 1; x <= n; x++) {
			for (int j = 1; j <= m; j++) {
				if (forbid[x][j]) {
					up[j] = 0;
				} else {
					up[j]++;
				}
			}
			for (int j = 1; j <= m; j++) {
				ll[j] = j - 1;
				while (ll[j] >= 1 && up[ll[j]] >= up[j]) 
					ll[j] = ll[ll[j]];
			}
			for (int j = m; j >= 1; j--) {
				rr[j] = j + 1;
				while (rr[j] <= m && up[rr[j]] >= up[j])
					rr[j] = rr[rr[j]];
			}
			for (int j = 1; j <= m; j++) {
				height[x][j] = up[j];
				width[x][j] = rr[j] - ll[j] - 1;
			}
		}
		int q;
		scanf("%d", &q);
		for (int i = 0; i < q; i++) {
			int l, r;
			scanf("%d%d", &l, &r);
			query[r].push_back(Query(l, i));
		}
		for (int x = 1; x <= n; x++) {
			for (int y = 1; y <= m; y++) {
				int h = height[x][y], w = width[x][y];
				int area = w * h;
			}
		}
	}
	return 0;
}

