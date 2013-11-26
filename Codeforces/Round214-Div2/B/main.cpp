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

int main() {
	int n, k;
	map<int, int> mp;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		mp[i % k] += x;
	}
	int ret = 1 << 30, ansi = 0;
	for (map<int, int>::iterator it = mp.begin(); it != mp.end(); it++) {
		if (it->second < ret) {
			ret = it->second;
			ansi = it->first + 1;
		}
	}
	cout << ansi << endl;
	return 0;
}

