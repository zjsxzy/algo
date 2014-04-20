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
	int m, n, mn, mx;
	cin >> n >> m >> mn >> mx;
	int fmn = false, fmx = false, flag = true;
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		if (x < mn || x > mx) flag = false;
		if (x == mn) fmn = true;
		if (x == mx) fmx = true;
	}
	if (!fmn && !fmx) {
		if (n - m < 2) {
			flag = false;
		}
	} else if (!fmn || !fmx) {
		if (n - m < 1) {
			flag = false;
		}
	}
	puts(flag ? "Correct" : "Incorrect");
	return 0;
}

