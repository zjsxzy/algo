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

const int MAXN = 10000 + 5;
int n, m;
int col[MAXN];
vector<int> adj[MAXN];
bool flag;
void dfs(int u, int c) {
	// cout << u << " " << c << endl;
	col[u] = c;
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i];
		if (col[v] != -1) {
			if (col[v] != 1 - c)
				flag = false;
		} else {
			dfs(v, 1 - c);
		}
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int ts;
	cin >> ts;
	while (ts--) {
		cin >> n >> m;
		for (int i = 0; i <= n; i++) {
			adj[i].clear();
			col[i] = -1;
		}
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			adj[a].PB(b);
			adj[b].PB(a);
		}
		flag = true;
		for (int i = 1; i <= n; i++) {
			if (col[i] == -1) {
				dfs(i, 0);
			}
		}
		puts(flag ? "Correct" : "Wrong");
	}
	return 0;
}

