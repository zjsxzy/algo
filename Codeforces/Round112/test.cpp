#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int e[100005][2];
int deg[100005];
vector<int> a[100005];
vector<int> g[100005];
int grp[100005], id[100005];
int conn[100005];
void dfs(int gp, int lev, int x, int from) {
	grp[x] = gp;
	id[x] = lev;
	g[gp].push_back(0);
	for(int i=0;i<(int)a[x].size();i++) {
		if(a[x][i]==from) continue;
		dfs(gp, lev+1, a[x][i], x);
	}
}

void add(int gp, int x, int val) {
	while(x<(int)g[gp].size()) {
		g[gp][x] += val;
		x += x&-x;
	}
}
int get(int gp, int x) {
	int ret=0;
	while(x>0) {
		ret += g[gp][x];
		x -= x&-x;
	}
	return ret;
}

int main(void) {
	int n;
	scanf("%d", &n);
	for(int i=1;i<n;i++) {
		scanf("%d%d", &e[i][0], &e[i][1]);
		deg[e[i][0]]++;
		deg[e[i][1]]++;
		a[e[i][0]].push_back(e[i][1]);
		a[e[i][1]].push_back(e[i][0]);
	}
	int root=1;
	for(int i=1;i<=n;i++) if(deg[i]>2) root = i;
	for(int i=0;i<(int)a[root].size();i++) {
		g[i].push_back(0);
		dfs(i, 1, a[root][i], root);
	}
	for(int i=1;i<n;i++) if(id[e[i][0]] < id[e[i][1]]) swap(e[i][0], e[i][1]);
	int m;
	scanf("%d", &m);
	for(int i=0;i<m;i++) {
		int type=0, ee;
		scanf("%d", &type);
		if(type==1) {
			scanf("%d", &ee);
			ee = e[ee][0];
			add(grp[ee], id[ee], -1);
		} else if(type==2) {
			scanf("%d", &ee);
			ee = e[ee][0];
			add(grp[ee], id[ee], 1);
		} else if(type==3) {
			int x, y;
			scanf("%d%d", &x, &y);
			if(grp[x] == grp[y]) {
				if(id[x] > id[y]) swap(x, y);
				int val = get(grp[y], id[y]) - get(grp[x], id[x]);
				if(val>0) printf("-1\n");
				else printf("%d\n", id[y]-id[x]);
			} else {
				int val = get(grp[y], id[y]) + get(grp[x], id[x]);
				if(val>0) printf("-1\n");
				else printf("%d\n", id[y] + id[x]);
			}
		}
	}
	return 0;
}
