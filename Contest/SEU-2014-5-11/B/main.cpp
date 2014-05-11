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
	int ts;
	cin >> ts;
	while (ts--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int cnt = 0;
			for (int k = 1; k <= 1 << n; k++) {
				if (k & (1 << i)) {
					cnt++;
					printf("%d%c", k, cnt == 1 << (n - 1) ? '\n' : ' ');
				}
			}
		}
	}
	return 0;
}

