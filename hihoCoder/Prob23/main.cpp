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

const int MAXN = 1000 + 5;
const int inf = 1000000000;
int n, m, S, T;
int dis[MAXN];
vector<pair<int, int> > adj[MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	cin >> n >> m >> S >> T;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back(make_pair(v, w));
		adj[v].push_back(make_pair(u, w));
	}
	for (int i = 1; i <= n; i++)
		dis[i] = inf;
	dis[S] = 0;
	priority_queue<pair<int, int> > pq;
	pq.push(make_pair(0, S));
	while (!pq.empty()) {
		int u = pq.top().second; pq.pop();
		for (int i = 0; i < adj[u].size(); i++) {
			int v = adj[u][i].first, tmp = dis[u] + adj[u][i].second;
			if (tmp < dis[v]) {
				dis[v] = tmp;
				pq.push(make_pair(-dis[v], v));
			}
		}
	}
	cout << dis[T] << endl;
	return 0;
}

