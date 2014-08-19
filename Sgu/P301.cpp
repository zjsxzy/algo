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

const int maxn = 2000 + 5;
const int inf = 1000000000;
int n, m, st, ed;
vector<pair<int, int> > adj[maxn];
int disS[maxn], disT[maxn];
int ans[maxn];
bool vis[maxn];

void spfa(int s, int dis[]) {
	for (int i = 1; i <= n; i++) {
		dis[i] = inf; vis[i] = false;
	}
	vis[s] = true;
	dis[s] = 0;
	queue<int> q;
	q.push(s);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		vis[u] = false;
		for (int i = 0; i < adj[u].size(); i++) {
			int v = adj[u][i].first, tmp = dis[u] + adj[u][i].second;
			if (tmp < dis[v]) {
				dis[v] = tmp;
				if (!vis[v]) {
					vis[v] = true;
					q.push(v);
				}
			}
		}
	}
}

const int maxm = 200000 + 5;
int edx[maxm], edy[maxm], edz[maxm];
pair<int, int> seg[maxm * 2];
int que[maxn];
int nque, nseg;

bool cmpque(int i, int j) {
	return disS[i] < disS[j];
}

int main() {
	scanf("%d%d%d", &n, &st, &ed);
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		adj[a].PB(MP(b, c)); adj[b].PB(MP(a, c));
		edx[i] = a; edy[i] = b; edz[i] = c;
	}
	spfa(st, disS);
	spfa(ed, disT);
	memset(ans, 0, sizeof(ans));
	nque = nseg = 0;
	for (int u = 1; u <= n; u++) {
		if (disS[u] + disT[u] != disS[ed]) {
			ans[u] = 0;
		} else {
			que[nque++] = u;
		}
	}
	for (int i = 0; i < m; i++) {
		int a = edx[i], b = edy[i], c = edz[i];
		if (disS[a] > disS[b]) swap(a, b);
		if (disS[a] + c == disS[b] && disS[a] + c + disT[b] == disS[ed]) {
			seg[nseg++] = MP(disS[a] + 1, 1);
			seg[nseg++] = MP(disS[b], -1);
		}
	}

	sort(que, que + nque, cmpque);
	sort(seg, seg + nseg);

	int cur = 0, sum = 0;
	for (int i = 0; i < nque; ) {
		int u = que[i], d = disS[u];
		while (cur < nseg && seg[cur].first <= d) {
			sum += seg[cur].second;
			cur++;
		}
		int j;
		for (j = i; j < nque && disS[que[j]] == disS[u]; j++) {
			ans[u]++;
		}
		ans[u] += sum;
		for (int k = i; k < j; k++)
			ans[que[k]] = ans[u];
		i = j;
	}
	for (int i = 1; i <= n; i++) {
		printf("%d%c", ans[i], i == n ? '\n' : ' ');
	}
	return 0;
}
