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
#include <cassert>
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

const int MAXN = 10000 + 5;
struct edge {
	int u, v, w;
	edge() {}
	edge(int u, int v, int w) : u(u), v(v), w(w) {}
	bool operator < (const edge &pt) const {
		return w < pt.w;
	}
};
int n, m, K, T;
vector<edge> ed;
vector<int> adj[MAXN];
int dis[MAXN];
bool check(int lim) {
	for (int i = 1; i <= n; i++) {
		adj[i].clear();
		dis[i] = -1;
	}
	for (int i = 0; i < m; i++) {
		if (ed[i].w > lim) continue;
		adj[ed[i].u].push_back(ed[i].v);
		adj[ed[i].v].push_back(ed[i].u);
	}
	queue<int> q;
	q.push(1);
	dis[1] = 0;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int i = 0; i < adj[u].size(); i++) {
			int v = adj[u][i];
			if (dis[v] == -1) {
				dis[v] = dis[u] + 1;
				q.push(v);
			}
		}
	}
	return dis[T] != -1 && dis[T] <= K;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	scanf("%d%d%d%d", &n, &m, &K, &T);
	for (int i = 0; i < m; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		ed.push_back(edge(u, v, w));
	}
	int lo = 0, hi = 1000000, ret = -1;
	while (lo <= hi) {
		int mid = (lo + hi) >> 1;
		if (check(mid)) {
			hi = mid - 1;
			ret = mid;
		} else {
			lo = mid + 1;
		}
	}
	printf("%d\n", ret);
	return 0;
}

