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

const int MAXN = 100 + 5;
const int MAXM = 10000 + 5;
const int inf = 1000000000;
int n, m;
int edx[MAXM], edy[MAXM], edw[MAXM];
int dis[MAXN][MAXN];
int main() {
#ifndef ONLINE_JUDGE
	// freopen("in.txt", "r", stdin);
#endif
	int ts;
	cin >> ts;
	for (int cas = 1; cas <= ts; cas++) {
		printf("Case #%d:\n", cas);
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				dis[i][j] = dis[j][i] = inf;
			}
		}
		for (int i = 0; i < m; i++) {
			int u, v, c;
			cin >> u >> v >> c;
			edx[i] = u; edy[i] = v; edw[i] = c;
			if (c < dis[u][v]) {
				dis[u][v] = dis[v][u] = c;
			}
		}
		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (dis[i][k] + dis[k][j] < dis[i][j]) {
						dis[i][j] = dis[i][k] + dis[k][j];
					}
				}
			}
		}
		for (int i = 0; i < m; i++) {
			if (dis[edx[i]][edy[i]] < edw[i]) {
				cout << i << endl;
			}
		}
	}
	return 0;
}

