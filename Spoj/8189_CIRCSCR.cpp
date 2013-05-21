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

const int MAXN = 20005;
struct SegTree {
	struct Node {
		int l, r, sum;
		int len;
		bool flag;
	}T[MAXN << 2];

	int lson(int rt) {return rt << 1;}
	int rson(int rt) {return rt << 1 | 1;}

	void pushUp(int rt) {
		T[rt].sum = T[lson(rt)].sum + T[rson(rt)].sum;
	}

	void pushDown(int rt) {
		if (T[rt].flag) {
			T[lson(rt)].flag = T[rson(rt)].flag = true;
			T[lson(rt)].sum = T[lson(rt)].len;
			T[rson(rt)].sum = T[rson(rt)].len;
			T[rt].flag = false;
		}
	}

	void build(int l, int r, int rt) {
		T[rt].l = l; T[rt].r = r; T[rt].sum = 0; T[rt].flag = false;
		T[rt].len = r - l + 1;
		if (l == r) return;
		int mid = (l + r) >> 1;
		build(l, mid, lson(rt));
		build(mid + 1, r, rson(rt));
	}

	void update(int L, int R, int rt) {
		if (L <= T[rt].l && T[rt].r <= R) {
			T[rt].flag = true;
			T[rt].sum = T[rt].len;
			return;
		}
		pushDown(rt);
		int mid = (T[rt].l + T[rt].r) >> 1;
		if (L <= mid) update(L, R, lson(rt));
		if (R > mid) update(L, R, rson(rt));
		pushUp(rt);
	}

}tree;
int w, h, n;
int x[111], y[111], r[111];

LL calc(int hgt) {
	//tree.build(0, w - 1, 1);
	vector<pair<int, int> > vec;
	for (int i = 0; i < n; i++) {
		int dh = abs(y[i] - hgt);
		if (dh > r[i]) continue;
		int dis = (int)sqrt(r[i] * r[i] - dh * dh);
		int l = max(0, x[i] - dis), r = min(w - 1, x[i] + dis);
		//cout << l << " " << r << endl;
		vec.PB(MP(l, r));
		//tree.update(l, r, 1);
	}
	sort(vec.begin(), vec.end());
	if (vec.size() == 0) return 0;
	LL ret = 0;
	int st = vec[0].first, ed = vec[0].second;
	for (int i = 1; i < vec.size(); i++) {
		if (vec[i].first <= ed) {
			ed = max(ed, vec[i].second);
		} else {
			ret += ed - st + 1;
			st = vec[i].first;
			ed = vec[i].second;
		}
	}
	ret += ed - st + 1;
	return ret;
	//return (LL)tree.T[1].sum;
}

int main(int argc, char const *argv[])
{
	int Test;
	scanf("%d", &Test);
	while (Test--) {
		scanf("%d%d%d", &w, &h, &n);
		for (int i = 0; i < n; i++) {
			scanf("%d%d%d", &x[i], &y[i], &r[i]);
		}
		LL ret = 0;
		for (int i = 0; i < h; i++) {
			ret += calc(i);
		}
		printf("%lld\n", (LL)w * h - ret);
	}
	return 0;
}