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

const int MAXN = 1000000 + 5;
int n, m, k;
struct edge {
	int u, v, w, mx;
	edge() {}
	edge(int u, int v, int w, int mx) : u(u), v(v), w(w), mx(mx) {}
	bool operator < (const edge &pt) const {
		// return w > pt.w;
		return w > pt.w;
	}
};
bool vis[MAXN];
int weight[MAXN];
vector<edge> ed;
struct DisJointSet{
	int rank[MAXN], parent[MAXN];

	void init(int n) {
		for (int i = 0; i <= n; i++) {
			rank[i] = 0;
			parent[i] = i;
		} 
	}

	int Find(int x) {
		if (parent[x] == x) return x;
		return parent[x] = Find(parent[x]);
	}

	void Union(int x, int y) {
		x = Find(x);
		y = Find(y);

		if (x == y) return;
		
		if (rank[x] >= rank[y]) {
			parent[y] = x;
			if (rank[x] == rank[y])
				rank[x]++;
		}
		else {
			parent[x] = y;
		}
	}

	int count(int n) {
		int ret = 0;
		for (int i = 1; i <= n; i++)
			ret += Find(i) == i;
		return ret;
	}
}djs;
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int ts;
	scanf("%d", &ts);
	for (int cas = 1; cas <= ts; cas++) {
		printf("Case #%d: ", cas);
		scanf("%d%d%d", &n, &m, &k);
		LL sum = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%d", weight + i);
			sum += (LL)weight[i];
		}
		memset(vis, false, sizeof(vis));
		djs.init(n);
		ed.clear();
		for (int i = 0; i < m; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			ed.PB(edge(u, v, weight[u], u));
			ed.PB(edge(u, v, weight[v], v));
			// int w, mx;
			// if (weight[u] > weight[v]) {
			// 	w = weight[u];
			// 	mx = u;
			//
			// } else {
			// 	w = weight[v];
			// 	mx = v;
			// 	ed.PB(edge(u, v, weight[v]))
			// }
			// ed.PB(edge(u, v, w, mx));
		}
		sort(ed.begin(), ed.end());
		// for (int i = 0; i < ed.size(); i++) {
		// 	cout << ed[i].u << " " << ed[i].v << " " << ed[i].w << endl;
		// }
		int cnt = 0;
		for (int i = 0; i < ed.size() && cnt < m - k; i++) {
			int u = ed[i].u, v = ed[i].v, w = ed[i].w, mx = ed[i].mx;
			if (vis[mx]) continue;
			int pu = djs.Find(u), pv = djs.Find(v);
			if (pu != pv) {
				// cout << u << " " << v << " " << w << endl;
				sum -= (LL)w;
				vis[mx] = true;
				cnt++;
				djs.Union(u, v);
			}
		}
		cout << sum << endl;
	}
	return 0;
}

