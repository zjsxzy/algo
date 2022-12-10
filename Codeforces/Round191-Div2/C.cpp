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

const LL MOD = 1000000007;
LL quickpow(LL a, LL x) {
	LL ret = 1;
	for (; x; x >>= 1) {
		if (x & 1) ret = (ret * a) % MOD;
		a = (a * a) % MOD;
	}
	return ret;
}
int main(int argc, char const *argv[])
{
	string s;
	int k;
	cin >> s;
	cin >> k;
	int n = s.size();

	LL ret = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '5' || s[i] == '0') {
			ret = ret + quickpow(2LL, (LL)i);
			ret %= MOD;
		}
	}

	LL pow2n = quickpow(2LL, (LL)n);
	ret = ret * (quickpow(pow2n, k) - 1) % MOD * quickpow(pow2n - 1, MOD - 2) % MOD;
	cout << ret << endl;
	return 0;
}