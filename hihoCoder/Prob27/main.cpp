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
const int MAXM = 1000000 + 5;
int n, m;
struct edge {
    int u, v, w;
    edge() {}
    edge(int u, int v, int w) : u(u), v(v), w(w) {}
    bool operator < (const edge &pt) const {
        return w < pt.w;
    }
}ed[MAXM];
int p[MAXN];
int find(int x) {
    return p[x] == x ? x : p[x] = find(p[x]);
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        p[i] = i;
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &ed[i].u, &ed[i].v, &ed[i].w);
    }
    sort(ed, ed + m);
    int ret = 0;
    for (int i = 0; i < m; i++) {
        int pu = find(ed[i].u), pv = find(ed[i].v);
        if (pu != pv) {
            p[pu] = pv;
            ret += ed[i].w;
        }
    }
    printf("%d\n", ret);
	return 0;
}

