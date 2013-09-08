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

const int inf = 100;

struct Point {
	int x[5];
	int change(char ch) {
		if ('0' <= ch && ch <= '9') return ch - '0';
		return ch - 'A' + 10;
	}
	void input() {
		char st[10];
		scanf("%s", st);
		for (int i = 0; i < 5; i++) {
			x[i] = change(st[i]);
		}
	}
};

int close(Point *ps, int l, int r) {
	if (r - l <= 1) return inf;
	res = inf;
	int m = (l + r) / 2, i;
	for (i = m; i >= l && ps[i].x[0] - ps[m].x[0] == 0; i--);
	int temp = close(ps, l, i + 1);
	if (temp < res) {
		res = temp;
	}
	for (i = m; i < r && ps[i].x[0] - ps[m].x[0] == 0; i++);
	temp = close(ps, i, r);
	if (temp < res) {
		res = temp;
	}
	int len = 0;
}

Point ps[100010];
int n;

int main() {
	int Test;
	scanf("%d", &Test);
	while (Test--) {
		scanf("%d", &n);
		for(int i = 0; i < n; i ++)	ps[i].input();
		int res = close(ps, l, r);
		printf("%d\n", res);
	}
	return 0;
}
