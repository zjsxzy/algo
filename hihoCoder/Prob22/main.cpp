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

const int MAXN = 100000 + 5;
int val[MAXN];
struct SegTree {

	int sum[MAXN << 2], add[MAXN << 2], put[MAXN << 2];

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
		if (m == 1) return;
		if (put[rt] != -1) {
			put[lson(rt)] = put[rt];
			put[rson(rt)] = put[rt];
			add[lson(rt)] = 0;
			add[rson(rt)] = 0;
			sum[lson(rt)] = put[rt] * (m - (m >> 1));
			sum[rson(rt)] = put[rt] * (m >> 1);
			put[rt] = -1;
		}
		if (add[rt] != 0) {
			add[lson(rt)] += add[rt];
			add[rson(rt)] += add[rt];
			sum[lson(rt)] += add[rt] * (m - (m >> 1));
			sum[rson(rt)] += add[rt] * (m >> 1);
			add[rt] = 0;
		}
	}
	
	void build(int l, int r, int rt) {
		add[rt] = 0;
		put[rt] = -1;
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

	void updateAdd(int L, int R, int c, int l, int r, int rt) {
		pushDown(rt, r - l + 1);
		if (L <= l && r <= R) {
			add[rt] += c;
			sum[rt] += c * (r - l + 1);
			return;
		}
		int mid = (l + r) >> 1;
		if (L <= mid) updateAdd(L, R, c, l, mid, lson(rt));
		if (R > mid) updateAdd(L, R, c, mid + 1, r, rson(rt));
		pushUp(rt);
	}
	
	void updateSet(int L, int R, int c, int l, int r, int rt) {
		pushDown(rt, r - l + 1);
		if (L <= l && r <= R) {
			put[rt] = c;
			sum[rt] = c * (r - l + 1);
			return;
		}
		int mid = (l + r) >> 1;
		if (L <= mid) updateSet(L, R, c, l, mid, lson(rt));
		if (R > mid) updateSet(L, R, c, mid + 1, r, rson(rt));
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
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i <= n; i++) {
		scanf("%d", val + i);
		// cout << val[i] << " ";
	}
	// cout << endl;
	tree.build(0, n, 1);
	// cout << tree.sum[1] << endl;
	for (int i = 0; i < m; i++) {
		int op, l, r, p;
		scanf("%d%d%d%d", &op, &l, &r, &p);
		// cout << op << " " << l << " " << r << " " << p << endl;
		if (op == 0) {
			tree.updateAdd(l, r, p, 0, n, 1);
		} else {
			tree.updateSet(l, r, p, 0, n, 1);
		}
		/*
		for (int j = 0; j <= n; j++)
			cout << tree.query(j, j, 0, n, 1) << " ";
		cout << endl;
		*/
		printf("%d\n", tree.query(0, n, 0, n, 1));
	}
	return 0;
}

