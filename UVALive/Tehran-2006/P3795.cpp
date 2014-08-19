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

const int MAXN = 300 + 5;
int mk[MAXN], cx[MAXN], cy[MAXN];
vector<int> adj[MAXN];
int n1, n2;

void addEdge(int u, int v) {
	adj[u].PB(v);
	//cout << u << "->" << v << endl;
}

int path(int u) {
	for (int i = 0, v; i < adj[u].size(); i++) {
		if (!mk[v = adj[u][i]]) {
			mk[v] = 1;
			if (cy[v] == -1 || path(cy[v])) {
				cx[u] = v;
				cy[v] = u;
				return 1;
			}
		}
	}
	return 0;
}

int MaxMatch() {
	memset(cx, -1, sizeof(cx));
	memset(cy, -1, sizeof(cy));
	int ret = 0;
	for (int i = 0; i < n1; i++) {
		if (cx[i] == -1) {
			memset(mk, 0, sizeof(mk));
			ret += path(i);
		}
	}
	return ret;
}

int fly[MAXN][MAXN];
int p[MAXN], rp[MAXN], q[MAXN], rq[MAXN];

bool beat(int i, int j, int T) {
	if (T < fly[i][j]) return false;
	if (rp[i] <= rq[j]) {
		return p[i] >= q[j] + (LL)T * rq[j];
	} else {
		return p[i] + (LL)(T - fly[i][j]) * rp[i] >= q[j] + (LL)T * rq[j];
	}
}

bool check(int T) {
	for (int i = 0; i < n1; i++) adj[i].clear();
	for (int i = 0; i < n1; i++) {
		for (int j = 0; j < n2; j++) {
			if (beat(i, j, T)) {
				addEdge(i, j);
			}
		}
	}
	int ret = MaxMatch();
	return ret == n2;
}

int main() {
	while (~scanf("%d%d", &n1, &n2) && n1 + n2) {
		for (int i = 0; i < n1; i++) {
			scanf("%d%d", p + i, rp + i);
		}
		for (int i = 0; i < n2; i++) {
			scanf("%d%d", q + i, rq + i);
		}
		for (int i = 0; i < n1; i++) {
			for (int j = 0; j < n2; j++) {
				scanf("%d", &fly[i][j]);
			}
		}

		int lo = 0, hi = 0x3f3f3f3f, res = -1;
		while (lo <= hi) {
			int mid = (lo + hi) >> 1;
			if (check(mid)) {
				res = mid;
				hi = mid - 1;
			} else lo = mid + 1;
		}
		if (res == -1) puts("IMPOSSIBLE");
		else printf("%d\n", res);
	}
	return 0;
}
