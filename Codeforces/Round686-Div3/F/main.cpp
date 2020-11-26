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
int n;
int a[MAXN], mx_front[MAXN], mx_end[MAXN];
struct SegTree {
	int mn[MAXN << 2];
	int lson(int rt) {return rt << 1;}
	int rson(int rt) {return rt << 1 | 1;}
	void pushUp(int rt) {
		mn[rt] = min(mn[lson(rt)], mn[rson(rt)]);
	}
	void build(int l, int r, int rt) {
		if (l == r) {
			mn[rt] = a[l];
			return;
		}
		int mid = (l + r) >> 1;
		build(l, mid, lson(rt));
		build(mid + 1, r, rson(rt));
		pushUp(rt);
	}
	int query(int L, int R, int l, int r, int rt) {
		if (L <= l && r <= R) {
			return mn[rt];
		}
		int mid = (l + r) >> 1;
		int res = INT_MAX;
		if (L <= mid) res = min(res, query(L, R, l, mid, lson(rt)));
		if (mid < R) res = min(res, query(L, R, mid + 1, r, rson(rt)));
		return res;
	}
}tree;

int check(int val, int l, int r) {
	int mn = tree.query(l, r, 1, n, 1);
	if (val > mn) return -1; // mn is too small, search in left range
	else if (val < mn) return 1; // mn is too large, search in right range 
	else { // mn == mx1
		if (val == mx_end[r + 1]) return 0;
		else if (val > mx_end[r + 1]) return -1; // mx2 is too small, search in left range 
		else if (val < mx_end[r + 1]) return 1; // mx2 is too large, search in right range
	}
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	tree.build(1, n, 1);
	mx_front[1] = a[1];
	for (int i = 2; i <= n; i++) {
		mx_front[i] = max(mx_front[i - 1], a[i]);
	}
	mx_end[n] = a[n];
	for (int i = n - 1; i >= 1; i--) {
		mx_end[i] = max(mx_end[i + 1], a[i]);
	}
	for (int x = 1; x <= n - 2; x++) {
		int mx1 = mx_front[x];
		int lo = x + 1, hi = n - 1;
		int y = -1;
		while (lo <= hi) {
			int mid = (lo + hi) >> 1;
			int t = check(mx1, x + 1, mid);
			if (t == 0) {
				y = mid;
				break;
			} else if (t == -1) {
				hi = mid - 1;
			} else {
				lo = mid + 1;
			}
		}
		if (y != -1) {
			cout << "YES" << endl;
			cout << x << " " << y - x << " " << n - y << endl;
			return;
		}
	}
	cout << "NO" << endl;
}

int main() {
	int ts;
	cin >> ts;
	while (ts--) {
		solve();
	}
    return 0;
}

