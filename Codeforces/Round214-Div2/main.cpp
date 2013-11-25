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

const int maxn = 1000 + 5;
const int maxm = 3000 + 5;
struct edge {
	int u, v, l, r;
	edge() {}
	edge(int u, int v, int l, int r) : u(u), v(v), l(l), r(r) {}
	bool operator < (const edge &pt) const {
		return r > pt.r;
	}
};
int n, m;
edge ed[maxm];
int p[maxn];

int find(int x) {
	return x == p[x] ? x : p[x] = find(p[x]);
}

int main() {
	cin >> n >> m;
	int lo = 0, hi = 0;
	for (int i = 0; i < m; i++) {
		int a, b, l, r;
		cin >> a >> b >> l >> r;
		ed[i] = edge(a, b, l, r);
		hi = max(hi, l);
	}
	sort(ed, ed + m);
	int ret = 0;
	for (int i = 0; i < m; i++) {
		int lo = ed[i].l;
		for (int j = 1; j <= n; j++) p[j] = j;
		for (int j = 0; j < m; j++) {
			if (ed[j].l <= lo) {
				int pu = find(ed[j].u), pv = find(ed[j].v);
				if (pu != pv) {
					p[pu] = pv;
				}
				if (find(1) == find(n)) {
					ret = max(ret, ed[j].r - lo + 1);
				}
			}
		}
	}
	if (ret == 0) cout << "Nice work, Dima!" << endl;
	else cout << ret << endl;
	return 0;
}

