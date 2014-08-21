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
#ifndef ONLINE_JUDGE
	freopen("in2.txt", "r", stdin);
#endif
	int n, m;
	cin >> n >> m;
	int cur = n;
	int day = 1;
	for (; cur > 0; day++) {
		if (day % m == 0) cur++;
		cur--;
	}
	cout << day - 1 << endl;
	return 0;
}

