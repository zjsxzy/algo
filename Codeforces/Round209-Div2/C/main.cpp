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

LL quickPow(LL a, LL x) {
	LL res = 1;
	for (; x; x >>= 1) {
		if (x & 1) res = res * a % MOD;
		a = a * a % MOD;
	}
	return res;
}

int main() {
	int n;
	LL x;
	cin >> n >> x;
	LL sum = 0, mx = 0;
	map<LL, int> mp;
	for (int i = 0; i < n; i++) {
		LL a;
		cin >> a;
		mp[a]++;
		sum += a;
		while (a > 0 && mp[a] == x) {
			mp[a] = 0;
			mp[--a]++;
		}
	}
	for (map<LL, int>::iterator it = mp.begin(); it != mp.end(); it++) {
		if (it->second != 0) {
			mx = max(mx, it->first);
		}
	}

	LL res = quickPow(x, sum - mx);
	cout << res << endl;
	return 0;
}
