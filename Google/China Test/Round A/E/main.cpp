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

const int maxn = 1600;
const int inf = 0x3f3f3f3f;
int n;
vector<pair<int, int> > adj[maxn];
int dis[maxn];
string col[80005];

int dijkstra(int s, int t) {
	for (int i = 0; i < n; i++) {
		dis[i] = inf;
	}
	dis[s] = 0;
	priority_queue<pair<int, int> > pq;
	pq.push(MP(0, s));
	while (!pq.empty()) {
		int u = pq.top().second; pq.pop();
		for (int i = 0; i < adj[u].size(); i++) {
			int v = adj[u][i].first, tmp = dis[u] + adj[u][i].second;
			if (tmp < dis[v]) {
				dis[v] = tmp;
				pq.push(MP(-dis[v], v));
			}
		}
	}
	if (dis[t] == inf) return -1;
	return dis[t];
}

int main() {
	int Test;
	scanf("%d\n", &Test);
	for (int cas = 1; cas <= Test; cas++) {
		printf("Case #%d:\n", cas);
		map<string, int> mp;
		n = 0;
		int m;
		cin >> m;
		for (int i = 1; i <= m; i++) {
			cin >> col[i];
			if (mp.find(col[i]) == mp.end()) {
				mp[col[i]] = n++;
			}
		}
		scanf("%d", &m);
		for (int i = 0; i < m; i++) {
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			adj[mp[col[a]]].PB(MP(mp[col[b]], c));
		}
		int p;
		scanf("%d", &p);
		while (p--) {
			int s, t;
			scanf("%d%d", &s, &t);
			if (col[s] == col[t]) {
				cout << 0 << endl;
			} else {
				int res = dijkstra(mp[col[s]], mp[col[t]]);
				printf("%d\n", res);
			}
		}
		for (int i = 0; i < n; i++) adj[i].clear();
	}
	return 0;
}
