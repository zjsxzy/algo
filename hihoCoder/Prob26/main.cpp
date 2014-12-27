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
    priority_queue<pair<int, int> > pq;
    pq.push(MP(0, 0));
    int ret = 0;
    while (!pq.empty()) {
        int u = pq.top().second; pq.pop();
		if (vst[u]) continue;
        ret += dis[u];
		// cout << u << " " << dis[u] << endl;
		vst[u] = true;
        for (int v = 0; v < n; v++) {
            if (u == v || vst[v]) continue;
            if (adj[u][v] < dis[v]) {
                dis[v] = adj[u][v];
                pq.push(MP(-dis[v], v));
            }
        }
    }
    printf("%d\n", ret);
	return 0;
}

