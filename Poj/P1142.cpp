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

const int maxn = 1000;
int tot;
int a[1000], b[1000];

void factor(int n, int a[maxn], int b[maxn], int &tot) {
	int temp, i, now;
	temp = (int)((double)sqrt(n) + 1);
	tot = 0;
	now = n;
	for (i = 2; i <= temp; i++)
		if (now % i == 0) {
			a[++tot] = i;
			b[tot] = 0;
			while (now % i == 0) {
				++b[tot];
				now /= i;
			}
		}
	if (now != 1) {
		a[++tot] = now;
		b[tot] = 1;
	}
}

//Miller-Rabin判断素数
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
	int a[] = {2, 3, 61}; //测试集，更广的测试范围需要更大的测试集
	for (int i = 0; i < 3; i++) {
		if (!test(n, a[i], n - 1)) return false;
 	}
 	return true;
}

int sumdig(int x) {
	int res = 0;
	for (; x; x /= 10) {
		res += x % 10;
	}
	return res;
}

int main() {
	int n;
	while (scanf("%d", &n) && n) {
		while (n++) {
			if (isPrime(n)) continue;
			tot = 0;
			factor(n, a, b, tot);
			int sum = 0;
			for (int i = 1; i <= tot; i++)
				for (int j = 0; j < b[i]; j++)
					sum += sumdig(a[i]);
			if (sumdig(n) == sum) break;
		}
		printf("%d\n", n);
	}
	return 0;
}
