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
#include <limits.h>
using namespace std;
#define PB push_back
#define MP make_pair
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
#define FOREACH(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
typedef long long LL;

const int maxn = 100005;
int n, m;
int val[maxn];

struct LeftistTree {
	int tot, v[maxn], l[maxn], r[maxn], d[maxn], p[maxn];

	LeftistTree():tot(0) {}

	void INIT(int n) {
		tot = 0;
		for (int i = 0; i < n + 1; i++) {
			p[i] = i;
		}
	}

	int merge(int x, int y) {
		if (!x) return y;
		if (!y) return x;
		if (v[x] < v[y]) swap(x, y);

		r[x] = merge(r[x], y);
		if (d[l[x]] < d[r[x]])
			swap(l[x], r[x]);
		d[x] = d[r[x]] + 1;
		return x;
	}

	int init(int x) {
		tot++;
		v[tot] = x;
		l[tot] = r[tot] = d[tot] = 0;
		return tot;
	}

	int insert(int x, int y) {
		return merge(x, init(y));
	}

	int top(int x) {
		return v[x];
	}

	int pop(int x) {
		return merge(l[x], r[x]);
	}

	int find(int x) {
		return x == p[x] ? x : find(p[x]);
	}
};

LeftistTree tree;

void work(int x, int y) {
	tree.v[x] /= 2; tree.v[y] /= 2;

	int tmp = tree.pop(x);
	tree.l[x] = tree.r[x] = tree.d[x] = 0;
	int xroot = tree.merge(tmp, x);

	tmp = tree.pop(y);
	tree.l[y] = tree.r[y] = tree.d[y] = 0;
	int yroot = tree.merge(tmp, y);

	tmp = tree.merge(xroot, yroot);
	tree.p[x] = tree.p[y] = tree.p[xroot] = tree.p[yroot] = tmp;
	printf("%d\n", tree.top(tmp));
}

int main() {
	while (~scanf("%d", &n)) {
		tree.INIT(n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &val[i]);
			tree.init(val[i]);
		}
		scanf("%d", &m);
		while (m--) {
			int x, y;
			scanf("%d%d", &x, &y);
			int px = tree.find(x), py = tree.find(y);
			if (px == py) printf("-1\n");
			else {
				work(px, py);	
			}
		}
	}
	return 0;
}
