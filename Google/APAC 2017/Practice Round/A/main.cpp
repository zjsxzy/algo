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

const int MOD = 1000000007;
LL solve(string str) {
	int n = str.size();
	LL res = 1l;
	for (int i = 0; i < n; i++) {
		int cnt = 1;
		if (i - 1 >= 0 && str[i - 1] != str[i]) cnt++;
		if (i + 1 < n && str[i + 1] != str[i]) cnt++;
		if (i - 1 >= 0 && i + 1 < n && str[i - 1] == str[i + 1] && str[i - 1] != str[i]) cnt--;
		res = (res * cnt) % MOD;
	}
	return res;
}

int main() {
#ifndef ONLINE_JUDGE
//	freopen("in.txt", "r", stdin);
#endif
	int ts;
	cin >> ts;
	for (int i = 0; i < ts; i++) {
		string str;
		cin >> str;
		LL res = solve(str);
		printf("Case #%d: %lld\n", i + 1, res);
	}
	return 0;
}
