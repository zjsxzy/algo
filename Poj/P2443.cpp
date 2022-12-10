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
#include <limits.h>
using namespace std;
#define PB push_back
#define MP make_pair
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
#define FOREACH(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
typedef long long LL;

const int MAXN = 10005;
LL b[MAXN][20];

bool check(int x, int y) {
	for (int i = 0; i < 20; i++) {
		if ((b[x][i] & b[y][i])) return true;
	}
	return false;
}

int main() {
	memset(b, 0, sizeof(b));
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int s;
		scanf("%d", &s);
		while (s--) {
			int c;
			scanf("%d", &c);
			b[c][i / 60] |= 1LL << (i % 60);
		}
	}
	int q;
	scanf("%d", &q);
	while (q--) {
		int x, y;
		scanf("%d%d", &x, &y);
		if (check(x, y)) puts("Yes");
		else puts("No");
	}
	return 0;
}
