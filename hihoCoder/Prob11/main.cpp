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

const int MAXN = 100000 + 5;
int n;
vector<int> adj[MAXN];
int dis[MAXN];

void bfs(int start) {
	queue<int> q;
	q.push(start);
	for (int i = 0; i < n; i++) {
		dis[i] = INT_MAX;
	}
	dis[start] = 0;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int i = 0; i < adj[u].size(); i++) {
			int v = adj[u][i];
			if (dis[v] > dis[u] + 1) {
				dis[v] = dis[u] + 1;
				q.push(v);
			}
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		a--; b--;
		adj[a].PB(b);
		adj[b].PB(a);
	}
	bfs(0);
	int leef = 0;
	for (int i = 0; i < n; i++) {
		// cout << dis[i] << endl;
		if (dis[i] > dis[leef]) {
			leef = i;
		}
	}
	bfs(leef);
	int res = 0;
	for (int i = 0; i < n; i++) {
		if (dis[i] > res) {
			res = dis[i];
		}
	}
	printf("%d\n", res);
	return 0;
}

