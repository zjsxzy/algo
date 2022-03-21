#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int maxn = 100005;
const LL inf = 1e12;
struct DisJointSet{
	int rank[maxn], parent[maxn];

	void init(int n) {
		for (int i = 0; i < n; i++) {
			rank[i] = 0;
			parent[i] = i;
		}
	}

	int Find(int x) {
		if (parent[x] == x) return x;
		return parent[x] = Find(parent[x]);
	}

	void Union(int x, int y) {
		x = Find(x);
		y = Find(y);

		if (x == y) return;

		if (rank[x] >= rank[y]) {
			parent[y] = x;
			if (rank[x] == rank[y])
				rank[x]++;
		}
		else {
			parent[x] = y;
		}
	}

	int count(int n) {
		int ret = 0;
		for (int i = 0; i < n; i++)
			ret += Find(i) == i;
		return ret;
	}
}uf;

void solve() {
	int n, m;
	cin >> n >> m;
	uf.init(n);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		uf.Union(u, v);
	}
	if (uf.Find(0) == uf.Find(n - 1)) {
		cout << 0 << endl;
		return;
	}
	set<LL> one, two;
	vector<int> val;
	vector<LL> d1(n, inf), dn(n, inf);
	int r1 = uf.Find(0), rn = uf.Find(n - 1);
	d1[r1] = 0; dn[rn] = 0;
	for (int i = 0; i < n; i++) {
		if (uf.Find(i) == r1) {
			one.insert(i);
		} else if (uf.Find(i) == rn) {
			two.insert(i);
		} else {
			val.push_back(i);
		}
	}

	LL res = inf;
	for (int i = 0; i < n; i++) {
		int f = uf.Find(i);
		auto j = one.lower_bound(i);
		LL dis = inf;
		if (j != one.end()) {
			dis = min(dis, (*j - i) * (*j - i));
		}
		if (j != one.begin()) {
			j--;
			dis = min(dis, (*j - i) * (*j - i));
		}
		d1[f] = min(d1[f], dis);

		j = two.lower_bound(i);
		dis = inf;
		if (j != two.end()) {
			dis = min(dis, (*j - i) * (*j - i));
		}
		if (j != two.begin()) {
			j--;
			dis = min(dis, (*j - i) * (*j - i));
		}
		dn[f] = min(dn[f], dis);
		res = min(res, d1[f] + dn[f]);
	}
	cout << res << endl;
}

int main() {
	int ts;
	cin >> ts;
	while (ts--) {
		solve();
	}
    return 0;
}

