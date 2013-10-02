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

const int MAXN = 200005;
int L, R, P, val;
int n, m;
#define Left l, mid
#define Right mid + 1, r
#define MID int mid = (l + r) >> 1;
void RD(int& x)
{
  x = 0; char c;
  for (c = getchar() ;!isdigit(c) ; c = getchar()); x = c - '0';
  for (c = getchar() ; isdigit(c) ; c = getchar()) x = x * 10 + c - '0';
}
struct SegTree {
	int mn[MAXN << 2], mx[MAXN << 2], add[MAXN << 2];
	void build(int l, int r, int rt) {
		mn[rt] = mx[rt] = add[rt] = 0;
		if (l == r) return;
		//int mid = (l + r) >> 1;
		MID;
		build(Left, rt << 1);
		build(Right, rt << 1 | 1);
	}
	void update(int l, int r, int rt) {
		if (L <= l && r <= R) {
			if (mx[rt] < P) {
				mx[rt] += val;
				mn[rt] += val;
				add[rt] += val;
				return;
			}
			if (mn[rt] >= P) {
				mx[rt] += val + val;
				mn[rt] += val + val;
				add[rt] += val + val;
				return;
			}
		}
		//int mid = (l + r) >> 1;
		MID;
		PushDown(rt);
		if (L <= mid) update(Left, rt << 1);
		if (R > mid) update(Right, rt << 1 | 1);
		PushUp(rt);
	}
	void PushUp(int rt) {
		int LL = rt << 1, RR = rt << 1 | 1;
		mx[rt] = max(mx[LL], mx[RR]);
		mn[rt] = min(mn[LL], mn[RR]);
	}
	void PushDown(int rt) {
		int LL = rt << 1, RR = rt << 1 | 1;
		if (add[rt]) {
			mx[LL] += add[rt];
			mn[LL] += add[rt];
			add[LL] += add[rt];

			mx[RR] += add[rt];
			mn[RR] += add[rt];
			add[RR] += add[rt];

			add[rt] = 0;
		}
	}
	void Print(int l, int r, int rt) {
		if (l == r) {
			printf("%d", add[rt]);
			if (l == n) printf("\n");
			else printf(" ");
			return;
		}
		PushDown(rt);
		//int mid = (l + r) >> 1;
		MID;
		Print(Left, rt << 1);
		Print(Right, rt << 1 | 1);
	}
}tree;

int main() {
	while (~scanf("%d%d%d", &n, &m, &P)) {
		tree.build(1, n, 1);
		while (m--) {
			RD(L); RD(R); RD(val);
			tree.update(1, n, 1);
		}
		tree.Print(1, n, 1);
	}
	return 0;
}
