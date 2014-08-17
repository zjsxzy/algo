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

const int MAXN = 200000 + 5;
int n;
int b[MAXN];

int main() {
	scanf("%d", &n);
	int mx = -1, mn = 1000000009;
	for (int i = 0; i < n; i++) {
		scanf("%d", b + i);
		mn = min(mn, b[i]);
		mx = max(mx, b[i]);
	}
	int t1 = 0, t2 = 0;
	for (int i = 0; i < n; i++) {
		if (b[i] == mn) t1++;
		if (b[i] == mx) t2++;
	}
	if (mn != mx) cout << mx - mn << " " << (LL)t1 * t2 << endl;
	else cout << 0 << " " << (LL)t1 * (t1 - 1) / 2 << endl;
	return 0;
}

