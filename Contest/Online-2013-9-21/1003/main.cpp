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
#include <limits.h>
using namespace std;
#define PB push_back
#define MP make_pair
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
#define FOREACH(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
typedef long long LL;

const int maxn = 10005;
const int maxm = 500005;
int n, m;
struct Edge {
	int u, v, w;
	bool operator < (const Edge &pt) const {
		return w < pt.w;
	}
}ed[maxm];
struct Query {
	int qe, id, ans;
}q[maxm];

bool cmp1(const Query &a, const Query &b) {
	return a.qe > b.qe;
}

bool cmp2(const Query &a, const Query &b) {
	return a.id < b.id;
}

int main() {
	while (~scanf("%d%d", &n, &m)) {
		for (int i = 0; i < m; i++) {
			scanf("%d%d%d", &ed[i].u, &ed[i].y, &ed[i].w);
		}
		for (int i = 0; i < n; i++) {
			p[i] = i;
		}

		sort(ed, ed + m);
		int query;
		scanf("%d", &query);
		for (int i = 0; i < query; i++) {
			scanf("%d", &q[i].qe);
			q[i].i = id;
		}
		sort(q, q + m, cmp1);
		for (int i = 0; i < query; i++) {
				
		}
	}
}
