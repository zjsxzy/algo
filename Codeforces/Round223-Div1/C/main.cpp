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

const int MAXN = 1000000 + 5;
char str[MAXN];
struct node {
	int m, l, r;
	node() {}
	node(int m, int l, int r) : m(m), l(l), r(r) {}
	void output() {
		printf("m = %d, l = %d, r = %d\n", m, l, r);
	}
};
node operator+ (const node &A, const node &B) {
	int t = min(A.l, B.r);
	int m = A.m + B.m + t;
	int l = A.l + B.l - t;
	int r = A.r + B.r - t;
	return node(m, l, r);
}
struct SegTree {
	node T[MAXN << 2];
	void build(int l, int r, int rt) {
		if (l == r) {
			if (str[l-1] == '(') {
				T[rt] = node(0, 1, 0);
			} else {
				T[rt] = node(0, 0, 1);
			}
			return;
		}
		T[rt] = node(0, 0, 0);
		int mid = (l + r) >> 1;
		build(l, mid, rt << 1);
		build(mid + 1, r, rt << 1 | 1);
		T[rt] = T[rt << 1] + T[rt << 1 | 1];
	}
	node query(int L, int R, int l, int r, int rt) {
		//printf("%d %d\n", l, r);
		if (L <= l && r <= R) {
			return T[rt];
		}
		int mid = (l + r) >> 1;
		node ret = node(0, 0, 0);
		if (L <= mid) ret = ret + query(L, R, l, mid, rt << 1);
		if (R > mid) ret = ret + query(L, R, mid + 1, r, rt << 1 | 1);
		return ret;
	}
}tree;

int main() {
	scanf("%s", str);
	int n = strlen(str);
	tree.build(1, n, 1);
	int q;
	scanf("%d", &q);
	while (q--) {
		int l, r;
		scanf("%d%d", &l, &r);
		node ret = tree.query(l, r, 1, n, 1);
		//ret.output();
		printf("%d\n", ret.m * 2);
	}
	return 0;
}

