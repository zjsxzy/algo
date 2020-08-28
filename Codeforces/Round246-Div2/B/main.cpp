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

int main() {
	int n;
	cin >> n;
	map<int, int> mp;
	vector<int> b(n);
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a >> b[i];
		mp[a]++;
	}
	for (int i = 0; i < n; i++) {
		cout << n - 1 + mp[b[i]] << " " << n - 1 - mp[b[i]] << endl;
	}
	return 0;
}

