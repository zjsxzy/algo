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

const int maxn = 55555;
struct LeftistTree {
	int tot, v[maxn], l[maxn], r[maxn], d[maxn];

	LeftistTree():tot(0) {}

	void INIT(int n) {
		tot = 0;
	}

	//x, y为要合并的两棵左偏树的编号，返回新的堆顶编号
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

	//向编号为x的左偏树中插入一个权值为y的节点
	int insert(int x, int y) {
		return merge(x, init(y));
	}

	//编号为x的左偏树的堆顶的权值
	int top(int x) {
		return v[x];
	}

	//删除编号为x的左偏树的堆顶
	int pop(int x) {
		return merge(l[x], r[x]);
	}

}tree;

int n;
int a[maxn], p[maxn], cnt[maxn], size[maxn];

int main() {
	while (~scanf("%d", &n) && n) {
		tree.INIT(n);
		memset(size, 0, sizeof(size));
		memset(cnt, 0, sizeof(cnt));
		memset(p, 0, sizeof(p));
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		int m = -1;
		for (int i = 0; i < n; i++) {
			p[++m] = tree.init(a[i]);
			size[m] = 1;
			cnt[m] = 1;
			while (m > 0 && tree.top(p[m]) <= tree.top(p[m - 1])) {
				p[m - 1] = tree.merge(p[m], p[m - 1]);
				size[m - 1] += size[m];
				cnt[m - 1] += cnt[m];
				m--;

				while (cnt[m] > (size[m] + 1) / 2) {
					p[m] = tree.pop(p[m]);
					cnt[m]--;
				}
			}
		}
		int k = 0;
		LL res = 0;
		for (int i = 0; i <= m; i++) {
			int val = tree.top(p[i]);
			for (int j = 0; j < size[i]; j++) {
				res += abs(val - a[k]);
				k++;
			}
		}
		cout << res << endl;
	}
	return 0;
}
