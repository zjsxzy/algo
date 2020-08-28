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
	int x1, x2, y1, y2;
	scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
	if (x1 == x2) {
		int len = abs(y1 - y2);
		printf("%d %d %d %d\n", x1 + len, y1, x1 + len, y2);
	} else if (y1 == y2) {
		int len = abs(x1 - x2);
		printf("%d %d %d %d\n", x1, y1 + len, x2, y2 + len);
	} else if (abs(x1 - x2) == abs(y1 - y2)) {
		printf("%d %d %d %d\n", x1, y2, x2, y1);
	} else {
		puts("-1");
	}
	return 0;
}

