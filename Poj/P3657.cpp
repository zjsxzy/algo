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

const int maxn = 1000000 + 5;
int n, m;
struct question {
	int l, r, a;
	int id;
	bool operator < (const question &pt) const {
		return a == pt.a ? l < pt.l : a > pt.a;
	}
}q[maxn];
int p[maxn];

int find(int x) {
	int q = x;
	for (; p[q] != q; q = p[q]);
	while (q != x) {
		int k = p[x];
		p[x] = q;
		x = k;
	}
	return q;
}

bool check(int mid) {
	for (int i = 1; i <= n + 1; i++) p[i] = i;
	for (int i = 1; i <= m; ) {
		while (q[i].id > mid) i++;
		if (i > m) return true;
		int j = i + 1, ll = q[i].l, rr = q[i].r;
		int l2 = ll, r2 = rr;
		for (; q[j].a == q[i].a && j <= m; j++) {
			if (q[j].id > mid) continue;
			rr = max(rr, q[j].r);
			l2 = q[j].l; r2 = min(r2, q[j].r);
		}
		if (l2 > r2) return false;
		if (find(l2) > r2) return false;
		for (int k = find(ll); k <= rr; k = find(k))
			p[k] = k + 1;
		i = j;
	}
	return true;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &q[i].l, &q[i].r, &q[i].a);
		q[i].id = i;
	}
	sort(q + 1, q + m + 1);
	if (check(m)) {
		puts("0");
		return 0;
	}
	int lo = 1, hi = m, ret = -1;
	while (lo <= hi) {
		int mid = (lo + hi) >> 1;
		if (check(mid)) {
			ret = mid;
			lo = mid + 1;
		} else hi = mid - 1;
	}
	printf("%d\n", lo);
	return 0;
}

