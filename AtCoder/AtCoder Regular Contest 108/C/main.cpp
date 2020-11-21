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

const int maxm = 200005;
struct DisJointSet{
	int rank[maxm], parent[maxm];

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

int n, m;
int u[maxm], v[maxm], c[maxm], vis[maxm];
map<pair<int, int> > cnt;

void output() {
    for (int i = 1; i <= n; i++) {
        cout << vis[i] << endl;
    }
}

void solve() {
    vector<pair<int, pair<int, int> > > vec;
    for (auto x : cnt) {
        vec.push_back({x.second, x.first});
    }
    sort(vec.begin(), vec.end());
    reverse(vec.begin(), vec.end());


    for (auto x : vec) {
        if (!vis[x.second.first]) {
            vis[x.second.first] = x.second.second;
        }
    }

    uf.init(n);
    int idx = n + 1;
    for (int i = 0; i < m; i++) {
        if (vis[u[i]] == c[i]) {
            uf.Union(u[i], v[i]);
        }
    }

    if (uf.count() == n) {
        output();
    } else {
        cout << "No" << endl;
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> u[i] >> v[i] >> c[i];
        cnt[{u[i], c[i]}]++;
        cnt[{v[i], c[i]}]++;
    }
    solve();
    return 0;
}

