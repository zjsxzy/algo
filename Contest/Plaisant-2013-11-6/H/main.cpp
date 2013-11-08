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

const int MAXN = 1005;
int n1;
int mk[MAXN], cx[MAXN], cy[MAXN];
vector<int> adj[MAXN];

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

int main() {
	int a, b;
	int n;
	scanf("%d%d%d", &a, &b, &n);
	vector<int> l, r;
	for (int i = 1; i <= n; i++) {
		int t, op;
		scanf("%d%d", &t, &op);
		if (op == 0) l.PB(t);
		else r.PB(t);
	}
	n1 = l.size();
	for (int i = 0; i < l.size(); i++) {
		for (int j = 0; j < r.size(); j++) {
			int dis = r[j] - l[i];
			if (dis < 0) continue;
			if (dis >= a || dis <= b) addEdge(i, j);
		}
	}
	int res = MaxMatch();
	if (res == l.size()) {
		puts("No reason");
		for (int i = 0; i < n1; i++)
			printf("%d %d\n", l[i], r[cx[i]]);
	} else {
		puts("Liar");
	}
	return 0;
}
