#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
using namespace std;

typedef long long LL;

const int SZ = 2, mod = 1000000007;

LL MUL[SZ][SZ], FSP[SZ][SZ];
void mul(LL a[SZ][SZ], LL b[SZ][SZ], int n) {
	memset(MUL, 0, sizeof(MUL));
	for (int k = 0; k < n; k++)
	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
		MUL[i][j] = (MUL[i][j] + a[i][k] * b[k][j]) % mod;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
		a[i][j] = MUL[i][j];
}

void fsp(LL base[SZ][SZ], LL Pow, int n) {
	memset(FSP, 0, sizeof(FSP));
	for (int i = 0; i < n; i++)
		FSP[i][i] = 1;
	while (Pow) {
		if (Pow & 1) mul(FSP, base, n);
		if (Pow >>= 1) mul(base, base, n);
	}
	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
		base[i][j] = FSP[i][j];
}

LL base[SZ][SZ];
int validstring(int n, int m) {
	LL a = n >> 1;
	LL b = (n + 1) >> 1;
	
	base[0][0] = 0;
	base[1][0] = 1;
	base[0][1] = b;
	base[1][1] = a * b % mod;
	fsp(base, m, 2);

	LL ret = (base[0][0] + base[1][0]) % mod;
	return (int) ret;
}

int main() {
	int n, m;
	while (~scanf("%d %d", &n, &m)) {
		int res = validstring(n, m);
		printf("%d\n", res);
	}
	return 0;
}
