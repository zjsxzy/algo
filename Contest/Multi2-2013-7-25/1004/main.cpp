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

const int MAXN = 50005;
struct SegTree {

	int sum[MAXN << 2], flag[MAXN << 2];

	int lson(int rt) {return rt << 1; }
	int rson(int rt) {return rt << 1 | 1; }

	void pushUp(int rt) {
		sum[rt] = sum[lson(rt)] + sum[rson(rt)];
	}

	void pushDown(int rt, int m) {
		if (flag[rt] != -1) {
			flag[lson(rt)] = flag[rt];
			flag[rson(rt)] = flag[rt];
			sum[lson(rt)] = (m - (m >> 1)) * flag[rt];
			sum[rson(rt)] = (m >> 1) * flag[rt];
			flag[rt] = -1;
		}
	}

	void build(int l, int r, int rt) {
		flag[rt] = -1;
		if (l == r) {
			sum[rt] = 0;
			return;
		}
		int mid = (l + r) >> 1;
		build(l, mid, lson(rt));
		build(mid + 1, r, rson(rt));
		pushUp(rt);
	}

	int query(int L, int R, int l, int r, int rt) {
		if (L <= l && r <= R) {
			return sum[rt];
		}
		pushDown(rt, r - l + 1);
		int mid = (l + r) >> 1;
		int ret = 0;
		if (L <= mid) ret += query(L, R, l, mid, lson(rt));
		if (R > mid) ret += query(L, R, mid + 1, r, rson(rt));
		return ret;
	}

	void update(int L, int R, int c, int l, int r, int rt) {
		if (L <= l && r <= R) {
			flag[rt] = c;
			sum[rt] = c * (r - l + 1);
			return;
		}
		pushDown(rt, r - l + 1);
		int mid = (l + r) >> 1;
		if (L <= mid) update(L, R, c, l, mid, lson(rt));
		if (R > mid) update(L, R, c, mid + 1, r, rson(rt));
		pushUp(rt);
	}
}tree;

int main(int argc, char const *argv[])
{
	int Test;
	scanf("%d", &Test);
	while (Test--) {
		int n, m;
		scanf("%d%d", &n, &m);
		tree.build(0, n - 1, 1);
		while (m--) {
			int op, a, b;
			scanf("%d%d%d", &op, &a, &b);
			if (op == 1) {
				int retl, retr;
				int lo = a - 1, hi = n;
				while (lo + 1 < hi) {
					int mid = (lo + hi) >> 1;
					if (tree.query(a, mid, 0, n - 1, 1) < mid - a + 1)
						hi = mid;
					else lo = mid;
				}
				retl = hi;

				if (retl >= n || b == 0) {
					puts("Can not put any one.");
				} else {
					lo = a, hi = n;
					while (lo + 1 < hi) {
						int mid = (lo + hi) >> 1;
						if (mid - a + 1 - tree.query(a, mid, 0, n - 1, 1) <= b)
							lo = mid;
						else hi = mid;
					}

					int v = lo;
					lo = a, hi = v + 1;
					while (lo + 1 < hi) {
						int mid = (lo + hi) >> 1;
						if (tree.query(mid, v, 0, n - 1, 1) < v - mid + 1)
							lo = mid;
						else hi = mid;
					}
					retr = lo;

					printf("%d %d\n", retl, retr);
					tree.update(retl, retr, 1, 0, n - 1, 1);
				}
			} else {
				int ret = tree.query(a, b, 0, n - 1, 1);
				printf("%d\n", ret);
				tree.update(a, b, 0, 0, n - 1, 1);
			}
		}
		printf("\n");
	}
	return 0;
}