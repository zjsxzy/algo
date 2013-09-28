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

const LL inf = 1LL << 60;
LL n, m;

LL solve(LL j, LL lambda) {
	LL a = 1, b = 100000 + j, c = j * j - 100000 * j - lambda;
	LL delta = b * b - 4 * a * c;
	if (delta < 0) return 0;
	double l = (-b - sqrt(delta * 1.0)) / (2 * a), r = (-b + sqrt(delta * 1.0)) / (2 * a);
	int u = ceil(l), v = floor(r);
	if (v <= 0) return 0;
	u = max(1, u), v = min(v, (int)n);
	return v - u + 1;
}

LL count(LL m) {
	LL ret = 0;
	for (int i = 1; i <= n; i++) {
		ret += solve(i, m);
	}
	return ret;
}

int main() {
	int Test;
	scanf("%d", &Test);
	while (Test--) {
		cin >> n >> m;
		LL lo = -inf, hi = inf;
		while (hi - lo > 1) {
			LL mid = (lo + hi) >> 1;
			if (count(mid) >= m) {
				hi = mid;
			} else {
				lo = mid;
			}
		}
		cout << hi << endl;
	}
	return 0;
}
