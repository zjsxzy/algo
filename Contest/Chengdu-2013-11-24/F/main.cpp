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

const int maxm = 100000 + 5;
struct Edge {
	int u, v, c;
	Edge() {}
	Edge(int u, int v, int c) : u(u), v(v), c(c) {}
}ed[maxm];
int p[maxm];
LL fib[maxm];
int n, m;
int n_fib;

bool cmp0(const Edge &A, const Edge &B) {
	return A.c < B.c;
}

bool cmp1(const Edge &A, const Edge &B) {
	return A.c > B.c;
}

int find(int x) {
	return p[x] == x ? x : p[x] = find(p[x]);
}

int mst() {
	for (int i = 1; i <= n; i++)
		p[i] = i;
	int ret = 0, cnt = 0;
	for (int i = 0; i < m; i++) {
		int pu = find(ed[i].u), pv = find(ed[i].v);
		if (pu != pv) {
			cnt++;
			ret += ed[i].c;
			p[pu] = pv;
		}
	}
	if (cnt < n - 1) return -1;
	return ret;
}

bool check(int l, int r) {	
	for (int i = 0; i <= n_fib; i++)
		if (l <= fib[i] && fib[i] <= r) return true;
	return false;
}

void pre() {
	fib[0] = 1;
	fib[1] = 1;
	n_fib = 1;
	for (int i = 2; fib[i - 1] + fib[i - 2] < maxm; i++) {
		fib[i] = fib[i - 1] + fib[i - 2];
		n_fib = max(n_fib, i);
	}
}

int main() {
	pre();
	int ts;
	scanf("%d", &ts);
	int cas = 1;
	//cout << n_fib << endl;
	while (ts--) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < m; i++) {
			scanf("%d%d%d", &ed[i].u, &ed[i].v, &ed[i].c);
		}
		sort(ed, ed + m, cmp0);
		int mn = mst();
		sort(ed, ed + m, cmp1);
		int mx = mst();
		//cout << mn << " " << mx << endl;
		if (mn == -1 || mx == -1) printf("Case #%d: No\n", cas++);
		else if (check(mn, mx)) printf("Case #%d: Yes\n", cas++);
		else printf("Case #%d: No\n", cas++);
	}
	return 0;
}
