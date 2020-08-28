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
int a[MAXN];
int n, m, w;

bool check(int lowest) {
	vector<int> add(n);
	LL need = 0, curAdd = 0;
	for (int i = 0; i < n; i++) {
		curAdd += add[i];
		LL cur = a[i] + curAdd;
		if (cur < lowest) {
			LL more = lowest - cur;
			curAdd += more;
			need += more;
			if (i + w < n) add[i + w] -= more;
		}
	}
	return need <= m;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in3.txt", "r", stdin);
#endif
	scanf("%d%d%d", &n, &m, &w);
	for (int i = 0; i < n; i++)
		scanf("%d", a + i);
	int lo = 0, hi = 1000100000, ret = -1;
	while (lo <= hi) {
		int mid = (lo + hi) >> 1;
		if (check(mid)) {
			ret = mid;
			lo = mid + 1;
		} else hi = mid - 1;
	}
	printf("%d\n", ret);
	return 0;
}

