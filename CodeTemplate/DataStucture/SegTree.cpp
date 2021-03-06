const int MAXN = 100005;
const int inf = 1e9;
int n;
int a[MAXN];
struct SegTree {
	int mx[MAXN << 2];
	int lson(int rt) {return rt << 1;}
	int rson(int rt) {return rt << 1 | 1;}
	void pushUp(int rt) {
		mx[rt] = max(mx[lson(rt)], mx[rson(rt)]);
	}
	void build(int l, int r, int rt) {
		if (l == r) {
			mx[rt] = a[l];
			return;
		}
		int mid = (l + r) >> 1;
		build(l, mid, lson(rt));
		build(mid + 1, r, rson(rt));
		pushUp(rt);
	}
	int query(int L, int R, int l, int r, int rt) {
		if (L <= l && r <= R) {
			return mx[rt];
		}
		int mid = (l + r) >> 1;
		int res = -inf;
		if (L <= mid) res = max(res, query(L, R, l, mid, lson(rt)));
		if (mid < R) res = max(res, query(L, R, mid + 1, r, rson(rt)));
		return res;
	}
    void update(int p, int val, int l, int r, int rt) {
        if (l == r) {
            mx[rt] = val;
            return;
        }
        int mid = (l + r) >> 1;
        if (p <= mid) update(p, val, l, mid, lson(rt));
        else update(p, val, mid + 1, r, rson(rt));
        pushUp(rt);
    }
}tree;
/*
 * 线段树有离散型和连续型两种。
 * 离散型线段树就是常规的线段树形式，叶子节点为[i,i]，区间分解为[l,mid]、[mid+1,r]
 * 当为连续型时，比如[3,6]表示的就是连续的一段区间，比如就算它被[3,5]、[5,6]覆盖，依然有(5,6)没有被覆盖。
 * 此时叶子节点为[i,i+1]，而区间[l,r]应该分解为[l,mid]、[mid,r]
 */
//离散型
const int MAXN = 5005;
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
		if (m == 1) return;
		if (add[rt]) {
			add[lson(rt)] += add[rt];
			add[rson(rt)] += add[rt];
			sum[lson(rt)] += add[rt] * (m - (m >> 1));
			sum[rson(rt)] += add[rt] * (m >> 1);
			add[rt] = 0;
		}
	}

	void build(int l, int r, int rt) {
		add[rt] = 0;
		sum[rt] = 0;
		if (l == r) {
			return;
		}
		int mid = (l + r) >> 1;
		build(l, mid, lson(rt));
		build(mid + 1, r, rson(rt));
		pushUp(rt);
	}

	void update(int L, int R, int c, int l, int r, int rt) {
		pushDown(rt, r - l + 1);
		if (L <= l && r <= R) {
			add[rt] += c;
			sum[rt] += c * (r - l + 1);
			return;
		}
		int mid = (l + r) >> 1;
		if (L <= mid) update(L, R, c, l, mid, lson(rt));
		if (R > mid) update(L, R, c, mid + 1, r, rson(rt));
		pushUp(rt);
	}

	int query(int L, int R, int l, int r, int rt) {
		pushDown(rt, r - l + 1);
		if (L <= l && r <= R) {
			return sum[rt];
		}
		int mid = (l + r) >> 1;
		int res = 0;
		if (L <= mid) res += query(L, R, l, mid, lson(rt));
		if (mid < R) res += query(L, R, mid + 1, r, rson(rt));
		return res;
	}
}tree;

//连续型
bool Hash[MAXN];
int ret;
struct SegTree {

	int col[MAXN << 2];

	int lson(int rt) {
		return rt << 1;
	}

	int rson(int rt) {
		return rt << 1 | 1;
	}

	void pushDown(int rt) {
		if (col[rt] != -1) {
			col[lson(rt)] = col[rt];
			col[rson(rt)] = col[rt];
			col[rt] = -1;
		}
	}

	void build(int l, int r, int rt) {
		col[rt] = -1;
		if (l + 1 == r) {
			return;
		}
		int mid = (l + r) >> 1;
		build(l, mid, lson(rt));
		build(mid, r, rson(rt));
	}

	void update(int L, int R, int c, int l, int r, int rt) {
		if (L <= l && r <= R) {
			col[rt] = c;
			return;
		}
		pushDown(rt);
		int mid = (l + r) >> 1;
		if (L < mid) update(L, R, c, l, mid, lson(rt));
		if (R > mid) update(L, R, c, mid, r, rson(rt));
	}

	void query(int l, int r, int rt) {
		if (col[rt] != -1) {
			if (!Hash[col[rt]]) {
				ret++;
				Hash[col[rt]] = true;
			}
			return;
		}
		if (l + 1 == r) return;
		int mid = (l + r) >> 1;
		query(l, mid, lson(rt));
		query(mid, r, rson(rt));
	}
}tree;

// 既有增加操作也有设置操作的线段是
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
