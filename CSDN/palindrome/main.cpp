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

const int MOD = 1000000007;
LL comb[105][105];

void getComb() {
	for (int i = 0; i <= 100; i++) {
		comb[i][0] = 1;
	}
	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= i; j++) {
			comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % MOD;
		}
	}
}

int palindrome(const string &s) {
	getComb();
	int n = s.size();
	map<char, int> mp;
	for (int i = 0; i < s.size(); i++) {
		mp[s[i]]++;
	}
	int odd = 0;
	for (map<char, int>::iterator it = mp.begin(); it != mp.end(); it++) {
		odd += (it->second & 1);
	}
	if (n & 1) {
		if (odd != 1) return 0;
	} else {
		if (odd > 0) return 0;
	}
	LL ret = 1;
	int tot = n / 2;
	for (map<char, int>::iterator it = mp.begin(); it != mp.end(); it++) {
		int cnt = it->second / 2;
		ret = (ret * comb[tot][cnt]) % MOD;
		tot -= cnt;
	}
	return (int)ret;
}

int main() {
	cout << palindrome("aaaabb") << endl;
	return 0;
}

