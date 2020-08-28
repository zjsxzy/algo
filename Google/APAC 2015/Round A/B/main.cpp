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

const int MAXN = 25;
int n;
string dir;
int mat[MAXN][MAXN], ans[MAXN][MAXN];
vector<int> merge(vector<int> vec) {
	vector<int> ret;
	ret.PB(vec[0]);
	bool merge = false;
	for (int j = 1; j < vec.size(); j++) {
		int last = ret[ret.size() - 1];
		if (last == vec[j] && !merge) {
			ret.pop_back();
			ret.PB(last * 2);
			merge = true;
		} else {
			ret.PB(vec[j]);
			merge = false;
		}
	}
	return ret;
}
void right() {
	memset(ans, 0, sizeof(ans));
	for (int i = 1; i <= n; i++) {
		vector<int> vec;
		for (int j = n; j >= 1; j--) {
			if (mat[i][j] != 0) vec.PB(mat[i][j]);
		}
		if (vec.size() > 0) {
			vector<int> ret = merge(vec);
			for (int j = 0; j < ret.size(); j++) {
				ans[i][n - j] = ret[j];
			}
		}
	}
}
void left() {
	memset(ans, 0, sizeof(ans));
	for (int i = 1; i <= n; i++) {
		vector<int> vec;
		for (int j = 1; j <= n; j++) {
			if (mat[i][j] != 0) vec.PB(mat[i][j]);
		}
		if (vec.size() > 0) {
			vector<int> ret = merge(vec);
			for (int j = 0; j < ret.size(); j++) {
				ans[i][j + 1] = ret[j];
			}
		}
	}
}
void up() {
	memset(ans, 0, sizeof(ans));
	for (int j = 1; j <= n; j++) {
		vector<int> vec;
		for (int i = 1; i <= n; i++) {
			if (mat[i][j] != 0) vec.PB(mat[i][j]);
		}
		if (vec.size() > 0) {
			vector<int> ret = merge(vec);
			for (int i = 0; i < ret.size(); i++) {
				ans[i + 1][j] = ret[i];
			}
		}
	}
}
void down() {
	memset(ans, 0, sizeof(ans));
	for (int j = 1; j <= n; j++) {
		vector<int> vec;
		for (int i = n; i >= 1; i--) {
			if (mat[i][j] != 0) vec.PB(mat[i][j]);
		}
		if (vec.size() > 0) {
			vector<int> ret = merge(vec);
			for (int i = 0; i < ret.size(); i++) {
				ans[n - i][j] = ret[i];
			}
		}
	}

}
void output() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%d%c", ans[i][j], j == n ? '\n' : ' ');
		}
	}
}
void solve() {
	scanf("%d", &n);
	cin >> dir;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &mat[i][j]);
		}
	}
	if (dir == "right") right();
	if (dir == "left") left();
	if (dir == "up") up();
	if (dir == "down") down();
	output();
}
int main() {
	int ts;
	scanf("%d", &ts);
	for (int cas = 1; cas <= ts; cas++) {
		printf("Case #%d:\n", cas);
		solve();
	}
	return 0;
}

