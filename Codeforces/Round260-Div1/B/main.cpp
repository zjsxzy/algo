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

const int MAXN = 100000 + 5;
const int ALPHA = 26;
int sz, root;
int chd[MAXN][ALPHA];
int win[MAXN], lose[MAXN];

void addTrie(string s) {
	int p = root;
	for (int i = 0; i < s.size(); i++) {
		int c = s[i] - 'a';
		if (chd[p][c] == 0) {
			chd[p][c] = ++sz;
		}
		p = chd[p][c];
	}
}

void dfs(int u) {
	win[u] = false;
	lose[u] = false;
	bool leaf = true;
	for (int c = 0; c < ALPHA; c++) {
		if (chd[u][c]) {
			leaf = false;
			int v = chd[u][c];
			dfs(v);
			win[u] |= !win[v];
			lose[u] |= !lose[v];
		}
	}
	if (leaf) {
		lose[u] = true;
	}
}

void answer(bool res) {
	puts(res ? "First" : "Second");
	exit(0);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in3.txt", "r", stdin);
#endif
	memset(chd, 0, sizeof(chd));
	int n, k;
	cin >> n >> k;
	root = ++sz;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		addTrie(s);
	}
	dfs(root);
	if (k == 1) answer(win[root]);
	else if (!win[root]) answer(win[root]);
	else if (lose[root]) answer(win[root]);
	else if (k % 2 == 1) answer(win[root]);
	else answer(!win[root]);
	return 0;
}

