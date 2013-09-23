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

const int maxNode = 400005;

struct Treap {
	int root, treapCnt, key[maxNode], priority[maxNode], childs[maxNode][2], cnt[maxNode], size[maxNode];

	Treap() {
		root = 0;
		treapCnt = 1;
		priority[0] = INT_MAX;
		size[0] = 0;
	}

	void update(int x) {
		size[x] = size[childs[x][0]] + cnt[x] + size[childs[x][1]];
	}

	void rotate(int &x, int t) {
		int y = childs[x][t];
		childs[x][t] = childs[y][1 - t];
		childs[y][1 - t] = x;
		update(x);
		update(y);
		x = y;
	}

	void __insert(int &x, int k) {
		if (x) {
			if (key[x] == k) {
				cnt[x]++;
			} else {
				int t = key[x] < k;
				__insert(childs[x][t], k);
				if (priority[childs[x][t]] < priority[x]) {
					rotate(x, t);
				}
			}
		} else {
			x = treapCnt++;
			key[x] = k;
			cnt[x] = 1;
			priority[x] = rand();
			childs[x][0] = childs[x][1] = 0;
		}
		update(x);
	}

	void __erase(int &x, int k) {
		if (key[x] == k) {
			if (cnt[x] > 1) {
				cnt[x]--;
			} else {
				if (childs[x][0] == 0 && childs[x][1] == 0) {
					x = 0;
					return;
				}
				int t = priority[childs[x][0]] > priority[childs[x][1]];
				rotate(x, t);
				__erase(x, k);
			}
		} else {
			__erase(childs[x][key[x] < k], k);
		}
		update(x);
	}

	int __getKth(int &x, int k) {
		if (k <= size[childs[x][0]]) {
			return __getKth(childs[x][0], k);
		}
		k -= size[childs[x][0]] + cnt[x];
		if (k <= 0) {
			return key[x];
		}
		return __getKth(childs[x][1], k);
	}

	void insert(int k) {
		__insert(root, k);
	}

	void erase(int k) {
		__erase(root, k);
	}

	int getKth(int k) {
		return __getKth(root, k);
	}
}treap;

struct DisJointSet {
	int p[maxNode], size[maxNode];

	void init(int n) {
		for (int i = 0; i < n; i++) {
			p[i] = i;
			size[i] = 1;
		}
	}

	int find(int x) {
		return x == p[x] ? x : p[x] = find(p[x]);
	}

	void uni(int x, int y) {
		int px = find(x), py = find(y);
		if (px != py) {
			p[py] = px;	
			treap.erase(size[px]);
			treap.erase(size[py]);
			size[px] += size[py];
			treap.insert(size[px]);
		}
	}
}ds;

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	ds.init(n + 1);
	for (int i = 1; i <= n; i++) {
		treap.insert(1);
	}
	for (int i = 0; i < m; i++) {
		int op;
		scanf("%d", &op);
		if (op == 0) {
			int l, r;
			scanf("%d%d", &l, &r);
			ds.uni(l, r);
		} else {
			int k;
			scanf("%d", &k);
			k = treap.size[treap.root] - k + 1;
			printf("%d\n", treap.getKth(k));
		}
	}
	return 0;
}
