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

int calc(long long n, long long k) {
	if (n == 1) return 0;
	if (k >= (1LL << n)) return calc(n - 1, k);
	if (k > (1LL << (n - 1))) return 1 - calc(n - 1, (1LL << n) - k);
	if (k == (1LL << (n - 1))) return 0;
	return calc(n - 1, k);
}
int main() {
#ifndef ONLINE_JUDGE
	// freopen("in.txt", "r", stdin);
#endif
	int ts;
	cin >> ts;
	for (int cas = 1; cas <= ts; cas++) {
		printf("Case #%d: ", cas);
		long long k;
		cin >> k;
		int res = calc(60, k);
		cout << res << endl;
	}
	return 0;
}
