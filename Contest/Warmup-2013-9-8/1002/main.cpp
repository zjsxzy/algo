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

const int maxn = 100005;
int dis[maxn];
vector<int> adj[maxn];
int main() {
	int Test;
	scanf("%d", &Test);
	while (Test--) {
		int n, d;
		scanf("%d%d", &n, &d);
		for (int i = 0; i < n; i++) adj[i].clear();
		memset(dis, -1, sizeof(dis));
		for (int i = 1; i < n; i++) {
			int a, b;
			scanf("%d%d", &a, &b);
			adj[a].PB(b); adj[b].PB(a);
		}
		int tot = 0;
		dis[0] = 0;
		queue<int> q;
		q.push(0);
		while (!q.empty()) {
			int u = q.front(); q.pop();
			if (dis[u] <= d) tot++;
			if (dis[u] >= d) continue;
			for (int i = 0; i < adj[u].size(); i++) {
				int v = adj[u][i];
				if (dis[v] == -1) {
					dis[v] = dis[u] + 1;
					q.push(v);
				}
			}
		}
		printf("%d\n", n - tot);
	}
	return 0;
}
