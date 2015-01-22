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
int n;
int adj[MAXN][MAXN], dis[MAXN];
bool vst[MAXN];
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        dis[i] = inf;
		vst[i] = false;
    }
    dis[0] = 0;
    int ret = 0;
	for (int i = 0; i < n; i++) {
		int min_value = inf, u = -1;
		for (int v = 0; v < n; v++) {
			if (!vst[v] && dis[v] < min_value) {
				min_value = dis[v];
				u = v;
			}
		}
		if (vst[u]) continue;
        ret += dis[u];
		// cout << u << " " << dis[u] << endl;
		vst[u] = true;
        for (int v = 0; v < n; v++) {
            if (u == v || vst[v]) continue;
            if (adj[u][v] < dis[v]) {
                dis[v] = adj[u][v];
            }
        }
    }
    printf("%d\n", ret);
	return 0;
}

