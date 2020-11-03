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

const int MAXN = 100 + 5;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, -1, -1};
stack<pair<int, int> > stk;
map<int, char> action;
int R, C, X;
int dir; // 0: Right, 1: Down, 2: Left, 3: Up
void makeMove() {
	while (stk.)
}
void solve() {
	int curr = 0;
	while (true) {
		curr++;
		makeMove();
	}
}
int main() {
#ifndef ONLINE_JUDGE
	// freopen("in.txt", "r", stdin);
#endif
	int ts;
	cin >> ts;
	for (int cas = 1; cas <= ts; cas++) {
		printf("Case #%d: ", cas);
		cin >> R >> C >> X;
		action.clear();
		while (!stk.empty()) {
			stk.pop();
		}
		for (int i = 0; i < X; i++) {
			int t;
			char move;
			scanf("%d %c\n", &t, &move);
			action[t] = t;
		}
		dir = 0;
		stk.push(MP(1, 1));
		solve();
	}
	return 0;
}

