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
	vector<vector<int>> comp(n);
	for (int i = 0; i < n; i++) {
		if (uf.Find(i) == uf.Find(0)) one.insert(i);
		else if (uf.Find(i) == uf.Find(n - 1)) two.insert(i);
		else {
			comp[uf.Find(i)].push_back(i);
		}
	}
	vector<int> root, val;
	for (int i = 0; i < n; i++) {
		if (comp[i].size() == 1) {
			val.push_back(i);
		} else if (comp[i].size() > 1) {
			root.push_back(i);
			sort(comp[i].begin(), comp[i].end());
		}
	}

	LL res = inf;
	for (auto x: one) {
		auto y = two.lower_bound(x);
		if (y != two.end()) {
			res = min(res, (*y - x) * (*y - x));
		}
		if (y != two.begin()) {
			y--;
			res = min(res, (*y - x) * (*y - x));
		}
	}
	for (auto x: val) {
		auto y = one.lower_bound(x);
		LL t1 = inf;
		if (y != one.end()) {
			t1 = min(t1, (*y - x) * (*y - x));
		}
		if (y != one.begin()) {
			y--;
			t1 = min(t1, (*y - x) * (*y - x));
		}

		y = two.lower_bound(x);
		LL t2 = inf;
		if (y != two.end()) {
			t2 = min(t2, (*y - x) * (*y - x));
		}
		if (y != two.begin()) {
			y--;
			t2 = min(t2, (*y - x) * (*y - x));
		}

		res = min(res, t1 + t2);
	}

	for (auto x: one) {
		auto z = two.lower_bound(x);
		if (z != two.end()) {
			for (auto u: root) {
				auto l = lower_bound(comp[u].begin(), comp[u].end(), x);
				auto r = upper_bound(comp[u].begin(), comp[u].end(), *z);
				if (r != comp[u].begin()) r--;
				if (r - l >= 0) {
					LL t = (*l - x) * (*l - x);
					t += (*z - *r) * (*z - *r);
					res = min(res, t);
				}
			}
		}
	}
	for (auto x: two) {
		auto z = one.lower_bound(x);
		if (z != one.end()) {
			for (auto u: root) {
				auto l = lower_bound(comp[u].begin(), comp[u].end(), x);
				auto r = upper_bound(comp[u].begin(), comp[u].end(), *z);
				if (r != comp[u].begin()) r--;
				if (r - l >= 0) {
					LL t = (*l - x) * (*l - x);
					t += (*z - *r) * (*z - *r);
					res = min(res, t);
				}
			}
		}
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

