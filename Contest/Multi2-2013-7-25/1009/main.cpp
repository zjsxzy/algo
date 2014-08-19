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
int mk[MAXN], cx[MAXN], cy[MAXN];
vector<int> adj[MAXN];
int n, m;

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
	for (int i = 0; i < n; i++) {
		if (cx[i] == -1) {
			memset(mk, 0, sizeof(mk));
			ret += path(i);
		}
	}
	return ret;
}

int Rx[MAXN], Ry[MAXN], Cx[MAXN], Cy[MAXN];
bool overlap(int i, int j) {
	if (Rx[i] == Cx[j] && Ry[i] == Cy[j]) return true;
	if (Rx[i] + 1 == Cx[j] && Ry[i] == Cy[j]) return true;
	if (Rx[i] == Cx[j] && Ry[i] == Cy[j] + 1) return true;
	if (Rx[i] + 1 == Cx[j] && Ry[i] == Cy[j] + 1) return true;
	return false; 
}

int main(int argc, char const *argv[])
{
	while (scanf("%d%d", &n, &m)) {
		if (n == 0 & m == 0) break;
		for (int i = 0; i < n; i++) adj[i].clear();
		for (int i = 0; i < n; i++)
			scanf("%d%d", Rx + i, Ry + i);
		for (int i = 0; i < m; i++)
			scanf("%d%d", Cx + i, Cy + i);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (overlap(i, j)) {
					addEdge(i, j);
				}
			}
		}
		int ret = MaxMatch();
		printf("%d\n", n + m - ret);
	}
	return 0;
}
