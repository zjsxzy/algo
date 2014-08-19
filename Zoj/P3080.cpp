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

const int inf = 1000000000;
const int maxn = 1000 + 5;
int n;
int adj[maxn][maxn], dis[maxn][maxn];
int len[maxn];
int mk[maxn];

void bfs(int st, int component) {
	queue<int> q;
	q.push(st);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		mk[u] = component;
		for (int v = 1; v <= n; v++) {
			if (u != v && adj[u][v] != -1 && !mk[v]) {
				q.push(v);
			}
		}
	}
}

int floyd(vector<int> graph) {
	for (int k = 0; k < graph.size(); k++)
		for (int i = 0; i < graph.size(); i++)
			for (int j = 0; j < graph.size(); j++) {
				if (i != j && j != k && k != i) {
					int vi = graph[i], vj = graph[j], vk = graph[k];
					dis[vi][vj] = min(dis[vi][vj], dis[vi][vk] + dis[vk][vj]);
				}
			}
	int res = inf;
	for (int i = 0; i < graph.size(); i++) {
		int vi = graph[i], mxdis = 0;
		for (int j = 0; j < graph.size(); j++) {
			int vj = graph[j];
			if (vi == vj) continue;
			mxdis = max(mxdis, dis[vi][vj]);
		}
		res = min(res, mxdis + len[vi]);
	}
	return res;
}

int main() {
	while (~scanf("%d", &n)) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				scanf("%d", &adj[i][j]);
				if (adj[i][j] == -1) dis[i][j] = inf;
				else dis[i][j] = adj[i][j];
			}
		}
		for (int i = 1; i <= n; i++) {
			scanf("%d", len + i);
		}
		memset(mk, 0, sizeof(mk));
		int component = 0;
		int res = 0;
		for (int i = 1; i <= n; i++) {
			if (mk[i]) continue;
			component++;
			bfs(i, component);
			vector<int> graph;
			for (int j = 1; j <= n; j++)
				if (mk[j] == component) graph.PB(j);
			int temp = floyd(graph);
			res = max(res, temp);
		}
		printf("%d\n", res);
	}
	return 0;
}
