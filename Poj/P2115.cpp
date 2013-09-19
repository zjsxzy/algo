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

LL extend_gcd(LL a, LL b, LL &x, LL &y) {
	if (b == 0) {
		x = 1; y = 0;
		return a;
	} else {
		LL r = extend_gcd(b, a % b, y, x);
		y -= x * (a / b);
		return r;
	}
}

int line_mod_equation(long long a, long long b, long long n) {
	long long x, y;
	long long d = extend_gcd(a, n, x, y);
	if (b % d == 0) {
		x %= n; x += n; x %= n;
		long long res = x * (b / d) % (n / d);
		for (int i = 0; i < d; i++) {
			long long tmp = (res + i * n / d) % n;
			if (tmp >= 0) return tmp;
		}
	}
	return -1;
}

int main() {
	LL a, b, c, k;
	while (cin >> a >> b >> c >> k, a || b || c || k) {
		LL aa, nn, bb;
		aa = c, nn = 1ll << k, bb = b - a;
		LL r = line_mod_equation(aa, bb, nn);
		if (r != -1) cout << r << endl;
		else cout << "FOREVER" << endl;
	}
	return 0;
}
