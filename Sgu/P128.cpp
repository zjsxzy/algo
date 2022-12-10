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

const int maxn = 10000 + 5;
const int maxS = 20000;
const int BASE = 10000;
struct SegTree {

	int sum[maxS << 2];

	int lson(int rt) {return rt << 1; }
	int rson(int rt) {return rt << 1 | 1; }

	void pushUp(int rt) {
		sum[rt] = sum[lson(rt)] + sum[rson(rt)];
	}

	void build(int l, int r, int rt) {
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
		int mid = (l + r) >> 1;
		int ret = 0;
		if (L <= mid) ret += query(L, R, l, mid, lson(rt));
		if (R > mid) ret += query(L, R, mid + 1, r, rson(rt));
		return ret;
	}

	void update(int pos, int c, int l, int r, int rt) {
		if (l == r) {
			sum[rt] += c;
			return;
		}
		int mid = (l + r) >> 1;
		if (pos <= mid) update(pos, c, l, mid, lson(rt));
		else update(pos, c, mid + 1, r, rson(rt));
		pushUp(rt);
	}
}tree;
struct Point {
	int x, y, idx;
}ps[maxn];
struct Seg {
	int a, b, c;
}seg[maxn << 1];
int n, n_seg;
vector<int> adj[maxn];
bool vis[maxn];

bool compx(const Point &A, const Point &B) {
	return A.x == B.x ? A.y < B.y : A.x < B.x;
}

bool compy(const Point &A, const Point &B) {
	return A.y == B.y ? A.x < B.x : A.y < B.y;
}

void addEdge(int a, int b) {
	adj[a].PB(b);
	adj[b].PB(a);
}

void addSeg(int a, int b, int c) {
	seg[n_seg].a = a; seg[n_seg].b = b; seg[n_seg].c = c;
	++n_seg;
}

void dfs(int u) {
	vis[u] = true;
	for (int i = 0, v; i < adj[u].size(); i++)
		if (!vis[v = adj[u][i]]) dfs(v);
}

bool comps(const Seg &A, const Seg &B) {
	return A.a == B.a ? A.c < B.c : A.a < B.a;
}

int main() {
	while (~scanf("%d", &n)) {
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &ps[i].x, &ps[i].y);
			ps[i].x += BASE; ps[i].y += BASE;
			ps[i].idx = i;
		}

		bool possible = true;
		int res = 0;
		n_seg = 0;
		// vertical lines
		sort(ps, ps + n, compx);
		int l = 0, r = 0;
		for (; l < n; ) {
			r = l + 1;
			while (r < n && ps[l].x == ps[r].x) {
				r++;
			}
			if ((r - l) & 1) possible = false;
			for (int i = l; i < r; i += 2) {
				if (i + 1 < r) {
					addEdge(ps[i].idx, ps[i + 1].idx);
					addSeg(ps[i].x, ps[i].y, ps[i + 1].y);
					res += ps[i + 1].y - ps[i].y;
				}
			}
			l = r;
		}

		// horizontal lines
		sort(ps, ps + n, compy);
		l = r = 0;
		for (; l < n; ) {
			r = l + 1;
			while (r < n && ps[l].y == ps[r].y) {
				r++;
			}
			if ((r - l) & 1) possible = false;
			for (int i = l; i < r; i += 2) {
				if (i + 1 < r) {
					addEdge(ps[i].idx, ps[i + 1].idx);
					addSeg(ps[i].x, ps[i].y, -1);
					addSeg(ps[i + 1].x, ps[i].y, -2);
					res += ps[i + 1].x - ps[i].x;
				}
			}
			l = r;
		}

		// check connectivity
		memset(vis, 0, sizeof(vis));
		dfs(0);
		for (int i = 0; i < n; i++)
			if (!vis[i]) {
				possible = false;
				break;
			}
		if (!possible) {
			puts("0");
			continue;
		}

		sort(seg, seg + n_seg, comps);
		tree.build(0, maxS, 1);
		for (int i = 0; i < n_seg; i++) {
			if (seg[i].c >= 0) { // vertical line
				int temp = tree.query(seg[i].b + 1, seg[i].c - 1, 0, maxS, 1);
				if (temp > 0) {
					possible = false;
					break;
				}
			} else { // horizontal line
				if (seg[i].c == -1) { // insert point
					tree.update(seg[i].b, 1, 0, maxS, 1);
				} else { // delete point
					tree.update(seg[i].b, -1, 0, maxS, 1);
				}
			}
		}
		if (!possible) {
			puts("0");
		} else {
			printf("%d\n", res);
		}
	}
	return 0;
}

