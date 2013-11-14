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

const int maxn = 5000 + 5;
const int inf = 0x3f3f3f3f;
int n;
int a[555];
int dis[maxn];
bool vis[maxn];
vector<pair<int, int> > adj[maxn];

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

void addEdge(int u, int v, int w) {
	adj[u].PB(MP(v, w));
//	cout << u << " -> " << v << " " << w << endl;
}

void spfa() {
	for (int i = 0; i < a[0]; i++) {
		dis[i] = inf;
		vis[i] = false;
	}
	dis[0] = 0;
	queue<int> q;
	q.push(0);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		vis[u] = false;
		for (int i = 0; i < adj[u].size(); i++) {
			int v = adj[u][i].first, tmp = dis[u] + adj[u][i].second;
			if (tmp < dis[v]) {
				dis[v] = tmp;
				if (!vis[v]) {
					vis[v] = true;
					q.push(v);
				}
			}
		}
	}
}

int main() {
	while (~scanf("%d", &n)) {
		int g = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", a + i);
			g = gcd(g, a[i]);
		}
		if (g > 1) {
			puts("INF");
			continue;
		}

		sort(a, a + n);

		for (int i = 0; i < a[0]; i++) adj[i].clear();
		for (int i = 0; i < a[0]; i++) {
			for (int j = 0; j < n; j++) {
				addEdge(i, (i + a[j]) % a[0], a[j]);
			}
		}

		spfa();
		int mx = 0;
		for (int i = 0; i < a[0]; i++)
			mx = max(mx, dis[i]);
		printf("%d\n", mx - a[0]);
	}
	return 0;
}
