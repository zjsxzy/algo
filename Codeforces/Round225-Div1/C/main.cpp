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

const int maxn = 200000 + 5;
struct BinaryIndexTree {
	int N;
	int C[maxn];
	
	void init(int N) {
		this->N = N;
		memset(C, 0, sizeof(C));
	}
	
	int lowbit(int x) {
		return x & (-x);
	}
	
	void add(int x, int num) {
		for (int i = x; i <= N; i += lowbit(i))
			C[i] += num;
	}
	
	int sum(int x) {
		int ret = 0;
		for (int i = x; i > 0; i -= lowbit(i))
			ret += C[i];
		return ret;
	}
}bit[2];

int n, m;
int a[maxn];
int TimeStamp;
int st[maxn], ed[maxn], order[maxn], depth[maxn];
vector<int> adj[maxn];

void dfs(int u, int fa) {
	st[u] = order[u] = ++TimeStamp;
	for (int i = 0, v; i < adj[u].size(); i++) {
		if ((v = adj[u][i]) != fa) {
			depth[v] = depth[u] ^ 1;
			dfs(v, u);
		}
	}
	ed[u] = TimeStamp;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].PB(v); adj[v].PB(u);
	}
	TimeStamp = 0;
	depth[1] = 0;
	dfs(1, 0);
	bit[0].init(n);
	bit[1].init(n);
	for (int i = 1; i <= n; i++) {
		bit[depth[i]].add(st[i], a[i]);
		bit[depth[i]].add(st[i] + 1, -a[i]);
	}
	for (int i = 0; i < m; i++) {
		int op;
		scanf("%d", &op);
		if (op == 1) {
			int x, val;
			scanf("%d%d", &x, &val);
			bit[depth[x]].add(st[x], val);
			bit[depth[x]].add(ed[x] + 1, -val);
			bit[depth[x] ^ 1].add(st[x], -val);
			bit[depth[x] ^ 1].add(ed[x] + 1, val);
		} else {
			int x;
			scanf("%d", &x);
			int res = bit[depth[x]].sum(st[x]);
			printf("%d\n", res);
		}
	}
	return 0;
}

