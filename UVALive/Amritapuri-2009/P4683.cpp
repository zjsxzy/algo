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

const int maxk = 15;
const int maxState = 1 << 15;
LL p[maxk], key[maxState];
int ones[maxState];
int k;
LL n;

LL gcd(LL a, LL b) {
	return b == 0 ? a : gcd(b, a % b);
}

LL lcm(LL a, LL b) {
	return a / gcd(a, b) * b;
}

LL calc(LL lim) {
	LL res = 0;
	for (int i = 1; i < (1 << k); i++) {
		int n_ones = ones[i];
		LL num = key[i];
		if (n_ones & 1) {
			for (int j = 0; j < k; j++) {
				if (((i >> j) & 1) == 1) {
					res += lim / num;
				}
			}
		} else {
			for (int j = 0; j < k; j++) {
				if (((i >> j) & 1) == 1) {
					res -= lim / num;
				}
			}
		}
	}
	return res;
}

int main() {
	int ts;
	cin >> ts;
	while (ts--) {
		cin >> k >> n;
		for (int i = 0; i < k; i++) {
			cin >> p[i];
		}
		for (int i = 1; i < (1 << k); i++) {
			ones[i] = 0;
			for (int j = i; j != 0; j -= j & -j)
				++ones[i];
			key[i] = 1;
			for (int j = 0; j < k; j++)
				if (((i >> j) & 1) == 1)
					key[i] = lcm(key[i], p[j]);
		}

		LL temp = calc(36);
		LL lo = 1, hi = 1000000000000000LL, res = -1;
		while (lo <= hi) {
			LL mid = (lo + hi) >> 1;
			LL temp = calc(mid);
			if (temp == n) {
				if (calc(mid - 1) < n) {
					res = mid;
					break;
				}
			}
			if (temp < n)
				lo = mid + 1;
			else hi = mid - 1;
		}
		cout << res << endl;
	}
	return 0;
}

