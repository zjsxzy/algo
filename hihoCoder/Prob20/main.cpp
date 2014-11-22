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

const int MAXN = 1000005;
int n;
int val[MAXN];
struct SegTree {

	int sum[MAXN << 2], add[MAXN << 2];

	int lson(int rt) {
		return rt << 1;
	}

	int rson(int rt) {
		return rt << 1 | 1;
	}

	void pushUp(int rt) {
		sum[rt] = sum[lson(rt)] + sum[rson(rt)];
	}

	void pushDown(int rt, int m) {
		if (add[rt]) {
			add[lson(rt)] = add[rt];
			add[rson(rt)] = add[rt];
			sum[lson(rt)] = add[rt] * (m - (m >> 1));
			sum[rson(rt)] = add[rt] * (m >> 1);
			add[rt] = 0;
		}
	}

	void build(int l, int r, int rt) {
		add[rt] = 0;
		sum[rt] = 0;
		if (l == r) {
			sum[rt] = val[l];
			return;
		}
		int mid = (l + r) >> 1;
		build(l, mid, lson(rt));
		build(mid + 1, r, rson(rt));
		pushUp(rt);
	}

	void update(int L, int R, int c, int l, int r, int rt) {
		if (L <= l && r <= R) {
			add[rt] = c;
			sum[rt] = c * (r - l + 1);
			return;
		}
		pushDown(rt, r - l + 1);
		int mid = (l + r) >> 1;
		if (L <= mid) update(L, R, c, l, mid, lson(rt));
		if (R > mid) update(L, R, c, mid + 1, r, rson(rt));
		pushUp(rt);
	}

	int query(int L, int R, int l, int r, int rt) {
		if (L <= l && r <= R) {
			return sum[rt];
		}
		pushDown(rt, r - l + 1);
		int mid = (l + r) >> 1;
		int res = 0;
		if (L <= mid) res += query(L, R, l, mid, lson(rt));
		if (mid < R) res += query(L, R, mid + 1, r, rson(rt));
		return res;
	}
}tree;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &val[i]);
	}
	tree.build(1, n, 1);
	int Q;
	scanf("%d", &Q);
	for (int i = 0; i < Q; i++) {
		int op;
		scanf("%d", &op);
		if (op == 0) {
			int a, b;
			scanf("%d%d", &a, &b);
			printf("%d\n", tree.query(a, b, 1, n, 1));
		} else {
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			tree.update(a, b, c, 1, n, 1);
		}
	}
	return 0;
}

