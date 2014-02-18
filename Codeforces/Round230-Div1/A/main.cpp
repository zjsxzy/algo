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

LL n;
bool inside(LL x, LL y) {
	return x * x + y * y <= n * n;
}
bool border(LL x, LL y) {
	if (!inside(x, y)) return false;
	if (!inside(x + 1, y) || !inside(x, y + 1)) return true;
	return false;
}
int main() {
	cin >> n;
	LL ret = 0, x = 0, y = n;
	if (n == 0) {
		cout << 1 << endl;
		return 0;
	}
	while (y > 0) {
		while (inside(x + 1, y)) {
			if (border(x, y)) ret++;
			x++;
		}
		if (border(x, y)) ret++;
		y--;
	}
	cout << ret * 4 << endl;
	return 0;
}

