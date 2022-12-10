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

const int inf = 100000000;
const int maxn = 1005;
int n, m;
int a[maxn], b[maxn];
int dp[15][maxn];
int cost[2][maxn][maxn];

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

int p[maxn], size[maxn], cnt[maxn];
int h[maxn], g[maxn];

int calc(int idx) {
	int res = h[idx] - 2 * g[idx] + (size[idx] & 1) * tree.top(p[idx]);
	return res;
}

void work(int start, int idx) {
	tree.INIT(n);
	memset(size, 0, sizeof(size));
	memset(cnt, 0, sizeof(cnt));
	memset(p, 0, sizeof(p));
	int tot = -1;
	int cst = 0;
	for (int j = start; j <= n; j++) {
		p[++tot] = tree.init(b[j]);
		size[tot] = 1;
		cnt[tot] = 1;
		g[tot] = h[tot] = b[j];
		while (tot > 0 && tree.top(p[tot]) <= tree.top(p[tot - 1])) {
			cst -= calc(tot);
			cst -= calc(tot - 1);
			p[tot - 1] = tree.merge(p[tot], p[tot - 1]);
			size[tot - 1] += size[tot];
			cnt[tot - 1] += cnt[tot];
			g[tot - 1] += g[tot];
			h[tot - 1] += h[tot];
			tot--;

			while (cnt[tot] > (size[tot] + 1) / 2) {
				g[tot] -= tree.top(p[tot]);
				p[tot] = tree.pop(p[tot]);
				cnt[tot]--;
			}
			cst += calc(tot);
		}
		cost[idx][start][j] = cst;
	}
}

int main() {
	while (~scanf("%d%d", &n, &m)) {
		if (n == 0 && m == 0) break;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			b[i] = a[i] - i;
		}
		for (int i = 1; i <= n; i++)
			work(i, 0);
		for (int i = 1; i <= n; i++)
			b[i] = -a[i] - i;
		for (int i = 1; i <= n; i++)
			work(i, 1);

		for (int i = 1; i <= n; i++)
			for (int j = i; j <= n; j++)
				cost[0][i][j] = min(cost[0][i][j], cost[1][i][j]);

		for (int i = 0; i <= m; i++)
			for (int j = 1; j <= n; j++)
				dp[i][j] = inf;

		dp[0][0] = 0;
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++)
				for (int k = 1; k <= j; k++)
					dp[i][j] = min(dp[i][j], dp[i - 1][k - 1] + cost[0][k][j]);

		printf("%d\n", dp[m][n]);
	}
	return 0;
}
