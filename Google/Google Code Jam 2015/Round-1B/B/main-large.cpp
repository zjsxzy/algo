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

int r, c, n, m;
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int ts;
	cin >> ts;
	for (int cas = 1; cas <= ts; cas++) {
		printf("Case #%d: ", cas);
		cin >> r >> c >> n;
		m = r * c;
		if (m % 2 == 0 && n <= m / 2) {
			cout << 0 << endl;
			continue;
		}
		if (m % 2 == 1 && n <= m / 2 + 1) {
			cout << 0 << endl;
			continue;
		}
	}
	return 0;
}

