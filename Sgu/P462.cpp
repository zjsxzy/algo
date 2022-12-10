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

const int maxn = 30000 + 5;
struct Edge {
	int a, b, r, p, id;
	Edge() {}
	Edge(int a, int b, int r, int p, int id) : a(a), b(b), r(r), p(p), id(id) {}
	bool operator < (const Edge &pt) const {
		return r == pt.r ? p > pt.p : r > pt.r;
	}
};
int n;
int fa[maxn];
vector<Edge> ed;

int find(int x) {
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}

int main() {

	while (~scanf("%d", &n)) {
		map<int, int> idx;
		ed.clear();
		int m = 0;
		for (int i = 0; i < n; i++) {
			int a, b, r, p;
			scanf("%d%d%d%d", &a, &b, &r, &p);
			if (idx.find(a) == idx.end()) {
				idx[a] = ++m;
			}
			if (idx.find(b) == idx.end()) {
				idx[b] = ++m;
			}
			ed.PB(Edge(idx[a], idx[b], r, p, i + 1));
		}
		sort(ed.begin(), ed.end());
		for (int i = 1; i <= m; i++) fa[i] = i;
		LL res = 0;
		for (int i = 0; i < n; i++) {
			int pa = find(ed[i].a), pb = find(ed[i].b);
			if (pa != pb) {
				res += ed[i].p;
				fa[pa] = pb;
			}
		}
		cout << res << endl;
		for (int i = ed.size() - 1; i >= 0; i--) {
			printf("%d%c", ed[i].id, i == 0 ? '\n' : ' ');
		}
	}
	return 0;
}
