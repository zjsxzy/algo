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

const int MAXN = 1005;
int n;
int parent[MAXN];
vector<pair<int, int> > cow;

int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

void merge(int x, int y) {
	x = find(x);
	y = find(y);
	parent[x] = y;
}

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, s;
		cin >> x >> s;
		cow.push_back({x, s});
	}
	sort(cow.begin(), cow.end());
	int R = 1e8;
	for (int i = 0; i < n - 1; i++) {
		if (cow[i].second == 0 && cow[i + 1].second == 1) {
			R = min(R, cow[i + 1].first - cow[i].first);
		}
		if (cow[i].second == 1 && cow[i + 1].second == 0) {
			R = min(R, cow[i + 1].first - cow[i].first);
		}
	}
	for (int i = 0; i < n; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < n; i++) {
		if (cow[i + 1].first - cow[i].first < R && cow[i + 1].second == 1 && cow[i].second == 1) {
			merge(i, i + 1);
		}
	}
	int res = 0;
	for (int i = 0; i < n; i++) {
        if (cow[i].second == 0) continue;
		res += find(i) == i;
	}
	cout << res << endl;
}

int main() {
	freopen("socdist2.in", "r", stdin);
	freopen("socdist2.out", "w", stdout);
	solve();
	return 0;
}

