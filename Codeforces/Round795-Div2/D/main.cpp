#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MAXN = 200005;
const LL inf = 1ll << 60;
int n;
LL s[MAXN], a[MAXN];
struct SegTree {
	LL mx[MAXN << 2], mn[MAXN << 2];
	int lson(int rt) {return rt << 1;}
	int rson(int rt) {return rt << 1 | 1;}
	void pushUp(int rt) {
        mn[rt] = min(mn[lson(rt)], mn[rson(rt)]);
		mx[rt] = max(mx[lson(rt)], mx[rson(rt)]);
	}
	void build(int l, int r, int rt) {
		if (l == r) {
			mx[rt] = s[l];
            mn[rt] = s[r];
			return;
		}
		int mid = (l + r) >> 1;
		build(l, mid, lson(rt));
		build(mid + 1, r, rson(rt));
		pushUp(rt);
	}
	LL query_min(int L, int R, int l, int r, int rt) {
		if (L <= l && r <= R) {
			return mn[rt];
		}
		int mid = (l + r) >> 1;
		LL res = inf;
		if (L <= mid) res = min(res, query_min(L, R, l, mid, lson(rt)));
		if (mid < R) res = min(res, query_min(L, R, mid + 1, r, rson(rt)));
		return res;
	}
	LL query_max(int L, int R, int l, int r, int rt) {
		if (L <= l && r <= R) {
			return mx[rt];
		}
		int mid = (l + r) >> 1;
		LL res = -inf;
		if (L <= mid) res = max(res, query_max(L, R, l, mid, lson(rt)));
		if (mid < R) res = max(res, query_max(L, R, mid + 1, r, rson(rt)));
		return res;
	}
}tree;

void solve() {
    cin >> n;
    s[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    vector<int> left(n + 1), right(n + 1);
    for (int i = 1; i <= n; i++) {
        left[i] = i - 1;
        while (left[i] >= 1 && a[left[i]] <= a[i]) {
            left[i] = left[left[i]];
        }
    }
    for (int i = n; i >= 1; i--) {
        right[i] = i + 1;
        while (right[i] <= n && a[right[i]] <= a[i]) {
            right[i] = right[right[i]];
        }
    }
    tree.build(0, n, 1);
    for (int i = 1; i <= n; i++) {
        LL r = tree.query_max(i, right[i] - 1, 0, n, 1);
        LL l = tree.query_min(left[i], i - 1, 0, n, 1);
        // cout << i << " " << a[i] << ' ' << left[i] << ' ' << right[i] << ' ' << r - l << endl;
        if (a[i] < r - l) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("in.txt", "r", stdin);
#endif
   int ts = 1;
   cin >> ts;
   for (int t = 1; t <= ts; t++) {
       solve();
   }
   return 0;
}

