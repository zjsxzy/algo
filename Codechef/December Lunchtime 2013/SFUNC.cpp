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

LL N, K, MOD;
LL ret;
vector<LL> p;

// x ^ b
LL pow(LL x, LL b) {
	LL ret = 1ll;
	for (; b; b >>= 1) {
		if (b & 1) ret = ret * x % MOD;
		x = x * x % MOD;
	}
	return ret;
}

void factor(LL n) {
	p.clear();
	for (LL i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			p.PB(i);
			do {
				n /= i;
			} while (n % i == 0);
		}
	}
	if (n > 1) p.PB(n);
}

LL gcd(LL a, LL b) {
	return b == 0 ? a : gcd(b, a % b);
}

LL sum(LL n) {
	LL ret = 1;
	if (K == 1) {
		LL a[] = {n, n + 1};
		LL b = 2;
		for (int i = 0; i < 2; i++) {
			LL g = gcd(a[i], b);
			a[i] /= g;
			b /= g;
			ret = a[i] % MOD * ret % MOD;
		}
		return ret;
	}
	if (K == 2) {
		LL a[] = {n, n + 1, 2 * n + 1};
		LL b = 6;
		for (int i = 0; i < 3; i++) {
			LL g = gcd(a[i], b);
			a[i] /= g;
			b /= g;
			ret = a[i] % MOD * ret % MOD;
		}
		return ret;
	}
	if (K == 3) {
		LL a[] = {n, n, n + 1, n + 1};
		LL b = 4;
		for (int i = 0; i < 4; i++) {
			LL g = gcd(a[i], b);
			a[i] /= g;
			b /= g;
			ret = a[i] = MOD * ret % MOD;
		}
		return ret;
	}
	if (K == 4) {
		LL a[] = {n, n + 1, 2 * n + 1, 3 * n * n + 3 * n - 1};
		LL b = 30;
		for (int i = 0; i < 4; i++) {
			LL g = gcd(a[i], b);
			a[i] /= g;
			b /= g;
			ret = a[i] % MOD * ret % MOD;
		}
		return ret;
	}
	return p[p.size()];
}

void dfs(int x, int cnt, LL mul, LL n) {
	if (x < 0) {
		LL temp = sum(n / mul) * pow(mul, K) % MOD;
		if (cnt & 1) ret -= temp;
		else ret += temp;
		return;
	} else {
		dfs(x - 1, cnt, mul, n);
		dfs(x - 1, cnt + 1, mul * p[x], n);
	}
}

int main() {
	while (cin >> N >> K >> MOD) {
		factor(N);
		ret = 0;
		dfs(p.size() - 1, 0, 1, N);
		ret = (ret % MOD + MOD) % MOD;
		cout << ret << endl;
	}
	return 0;
}

