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

const int MAXN = 1000 + 5;
int D;
int p[MAXN];
int solve(int k) {
	int cnt = 0;
	for (int i = 0; i < D; i++) {
		if (p[i] > k) {
			cnt += p[i] % k == 0 ? p[i] / k  - 1: p[i] / k;
		}
	}
	return cnt + k;
}
int main() {
#ifndef ONLINE_JUDGE
	// freopen("in.txt", "r", stdin);
#endif
	int ts;
	cin >> ts;
	for (int cas = 1; cas <= ts; cas++) {
		cin >> D;
		int mx = 0;
		for (int i = 0; i < D; i++) {
			cin >> p[i];
			mx = max(mx, p[i]);
		}
		int ret = mx;
		for (int k = 2; k <= mx; k++) {
			int tmp = solve(k);
			ret = min(ret, tmp);
		}
		printf("Case #%d: %d\n", cas, ret);
	}
	return 0;
}

