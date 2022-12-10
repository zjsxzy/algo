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

int pow_mod(int a, int i, int n) {
	if (i == 0) return 1 % n;
	int res = 1;
	for (; i; i >>= 1) {
		if (i & 1) res = (long long)res * a % n;
		a = (long long)a * a % n;
	}
	return res;
}

bool test(int n, int a, int d) {
	if (n == 2) return true;
	if (n == a) return true;
	if ((n & 1) == 0) return false;
	while (!(d & 1)) d = d >> 1;
	int t = pow_mod(a, d, n);
	while ((d != n - 1) && (t != 1) && (t != n - 1)) {
		t = (long long)t * t % n;
		d = d << 1;
	}
	return (t == n - 1 || (d & 1) == 1);
}

bool isPrime(int n) {
	if (n < 2) return false;
	int a[] = {2, 3, 61};
	for (int i = 0; i < 3; i++) {
		if (!test(n, a[i], n - 1)) return false;
 	}
 	return true;
}

int main(int argc, char const *argv[])
{
	int n;
	while (~scanf("%d", &n)) {
		int res = 0;
		for (int i = 0; i < n; i++) {
			int x;
			scanf("%d", &x);
			if (isPrime(x)) res++;
		}
		printf("%d\n", res);
	}
	return 0;
}