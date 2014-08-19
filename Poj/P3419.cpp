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

const int maxn = 200005;
const int BASE = 1000000;
int n, q;
int val[maxn];
int pre[2 * BASE + 5];
int st[maxn];
int rmq[2 * maxn];
struct ST {
	int mm[2 * maxn];
	int best[20][2 * maxn];

	void init(int n) {
		int i, j, a, b;
		mm[0] = -1;
		for (i = 1; i <= n; i++) {
			mm[i] = ((i & (i - 1)) == 0 ? mm[i - 1] + 1 : mm[i - 1]);
			best[0][i] = i;
		}
		for (i = 1; i <= mm[n]; i++) {
			for (j = 1; j <= n + 1 - (1 << i); j++) {
				a = best[i - 1][j];
				b = best[i - 1][j + (1 << (i - 1))];
				best[i][j] = rmq[a] > rmq[b] ? a : b;
			}
		}
	}

	int query(int a, int b) {
		if (a >  b) swap(a, b);
		int t;
		t = mm[b - a + 1];
		a = best[t][a];
		b = best[t][b - (1 << t) + 1];
		return rmq[a] > rmq[b] ? a : b;
	}
}ST;
struct Query {
	int l, r, res, id;
	bool operator < (const Query &pt) const {
		return l < pt.l;
	}
}que[maxn];

/*
int work(int l, int r) {
	if (st[r] <= l) return r - l + 1;
	int lo = 1, hi = n, ret = -1;
	while (hi - lo >= 1) {
		int mid = (lo + hi) >> 1;
		if (st[mid] >= l) {
			ret = mid;
			hi = mid;
		} else {
			lo = mid;
		}
	}
	int temp = ST.query(ret, r);
	int res = max(rmq[ret], rmq[temp]);
	return res;
}
*/

bool cmp(const Query &A, const Query &B) {
	return A.id < B.id;
}

int main() {
	while (~scanf("%d%d", &n, &q)) {
		memset(st, 0, sizeof(st));
		memset(pre, 0, sizeof(pre));

		for (int i = 1; i <= n; i++)
			scanf("%d", &val[i]);
		pre[val[1] + BASE] = 1;
		st[1] = 1;
		for (int i = 2; i <= n; i++) {
			int key = val[i] + BASE;
			if (pre[key] + 1 <= st[i - 1]) {
				st[i] = st[i - 1];
			} else {
				st[i] = pre[key] + 1;
			}
			pre[key] = i;
		}
		for (int i = 1; i <= n; i++)
			rmq[i] = i - st[i] + 1;
		ST.init(n);

		for (int i = 0; i < q; i++) {
			scanf("%d%d", &que[i].l, &que[i].r);
			que[i].l++; que[i].r++;
			que[i].id = i;
		}
		sort(que, que + q);
		int p = 1;
		for (int i = 0; i < q; i++) {
			for (; p <= n && st[p] < que[i].l; p++);

			if (st[que[i].r] <= que[i].l) {
				que[i].res = que[i].r - que[i].l + 1;
				continue;
			}
			int temp = ST.query(p, que[i].r);
			que[i].res = max(p - que[i].l, rmq[temp]);
		}
		sort(que, que + q, cmp);
		for (int i = 0; i < q; i++) {
			printf("%d\n", que[i].res);
		}
	}
	return 0;
}
