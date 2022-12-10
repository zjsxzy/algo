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

const int inf = 100000;
const int maxn = 100005;
int n, m;
int cost[maxn], rank[maxn], p[maxn];

inline int find(int x) {
	return p[x] == x ? x : p[x] = find(p[x]);
}

inline void uni(int x, int y) {
	if (rank[x] >= rank[y]) {
		p[y] = x;
		if (rank[x] == rank[y]) rank[x]++;
	} else {
		p[x] = y;
	}
}

int main(int argc, char const *argv[])
{
	while (~scanf("%d%d", &n, &m)) {
		for (int i = 1; i <= n; i++) {
			rank[i] = 0;
			p[i] = i;
			cost[i] = inf;
		}
		for (int i = 0; i < m; i++) {
			int a, b;
			scanf("%d%d", &a, &b);
			int pa = find(a), pb = find(b);
			if (pa == pb) continue;
			uni(pa, pb);
		}
		for (int i = 1; i <= n; i++) {
			int c;
			scanf("%d", &c);
			if (c < 0) continue;
			int fa = find(i);
			if (c < cost[fa]) {
				cost[fa] = c;
			}
		}
		int sum = 0, cnt = 0, Min = inf;
		bool flag = true;
		for (int i = 1; i <= n; i++) {
			int fa = find(i);
			if (fa == i) {
				if (cost[i] == inf) {
					flag = false;
					break;
				}
				cnt++;
				sum += cost[i];
				if (cost[i] < Min) {
					Min = cost[i];
				}
			}
		}
		printf("%d\n", flag ? sum + Min * (cnt - 2) : -1);
	}
	return 0;
}