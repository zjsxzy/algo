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

void solve() {
	int n;
    cin >> n;
	vector<vector<int> > adj(n);
	vector<int> deg(n, 0);
    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
		u--; v--;
        adj[u].push_back(v);
		adj[v].push_back(u);
		deg[u]++; deg[v]++;
    }
	vector<LL> cnt(n, 1);
	queue<int> q;
	for (int i = 0; i < n; i++) {
		if (deg[i] == 1) {
			q.push(i);
		}
	}
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (auto v : adj[u]) {
			deg[v]--;
			if (deg[v] == 1) {
				q.push(v);
			}
			cnt[v] += cnt[u];
		}
	}
	LL res = 0;
	for (int i = 0; i < n; i++) {
		if (deg[i] == 2) { // vertex on circle
			res += cnt[i] * (cnt[i] - 1) / 2;
			res += cnt[i] * (n - cnt[i]);
		}
	}
	cout << res << endl;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
    int ts;
    cin >> ts;
    while (ts--) {
        solve();
    }
    return 0;
}

