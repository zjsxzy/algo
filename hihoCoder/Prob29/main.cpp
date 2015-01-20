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

const int MAXN = 100000 + 5;
const int inf = 1000000000;
int n, m;
vector<pair<int, int> > adj[MAXN];
int dis[MAXN];
bool vst[MAXN];
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        adj[a].PB(MP(b, c));
        adj[b].PB(MP(a, c));
    }
    for (int i = 0; i <= n; i++) {
        dis[i] = inf;
		vst[i] = false;
    }
    dis[1] = 0;
    priority_queue<pair<int, int> > pq;
    pq.push(MP(0, 1));
    int ret = 0;
    while (!pq.empty()) {
        int u = pq.top().second; pq.pop();
		if (vst[u]) continue;
        ret += dis[u];
		// cout << u << " " << dis[u] << endl;
		vst[u] = true;
        for (vector<pair<int, int> >::iterator it = adj[u].begin(); it != adj[u].end(); it++) {
            int v = it->first, w = it->second;
			// cout << v << " " << w << endl;
            if (u == v || vst[v]) continue;
            if (w < dis[v]) {
                dis[v] = w;
                pq.push(MP(-dis[v], v));
            }
        }
    }
    printf("%d\n", ret);
	return 0;
}

