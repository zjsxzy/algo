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