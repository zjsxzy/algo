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

const int MAXN = 10000 + 5;
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
		if (l == r) {
			return;
		}
		int mid = (l + r) >> 1;
		build(l, mid, lson(rt));
		build(mid + 1, r, rson(rt));
	}

	void update(int L, int R, int c, int l, int r, int rt) {
		if (L <= l && r <= R) {
			col[rt] = c;
			return;
		}
		pushDown(rt);
		int mid = (l + r) >> 1;
		if (L <= mid) update(L, R, c, l, mid, lson(rt));
		if (R > mid) update(L, R, c, mid + 1, r, rson(rt));
	}

	void query(int l, int r, int rt) {
		if (col[rt] != -1) {
			if (!Hash[col[rt]]) {
				ret++;
				Hash[col[rt]] = true;
			}
			return;
		}
		if (l == r) return;
		int mid = (l + r) >> 1;
		query(l, mid, lson(rt));
		query(mid + 1, r, rson(rt));
	}
}tree;
int n, L;
int ll[MAXN], rr[MAXN];
vector<int> as;
void compress() {
	vector<int> num;
	for (int i = 0; i < as.size(); i++) {
		num.PB(as[i]);
	}
	sort(num.begin(), num.end());
    num.resize(unique(num.begin(), num.end()) - num.begin());
	for (int i = 0; i < as.size(); i++) {
		as[i] = lower_bound(num.begin(), num.end(), as[i]) - num.begin() + 1;
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	int ts;
	scanf("%d", &ts);
	while (ts--) {
		as.clear();
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &ll[i], &rr[i]);
			as.push_back(ll[i]); as.push_back(rr[i]);
		}
		compress();
		tree.build(1, 2 * n, 1);
		for (int i = 0; i < n; i++) {
			int l = as[2 * i], r = as[2 * i + 1];
			tree.update(l, r, i, 1, 2 * n, 1);
		}
		memset(Hash, 0, sizeof(Hash));
		ret = 0;
		tree.query(1, 2 * n, 1);
		printf("%d\n", ret);
	}
	return 0;
}
