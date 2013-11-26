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

const int maxn = 100000 + 5;
int n;
int height[maxn], ll[maxn], rr[maxn];

int main() {
	while (scanf("%d", &n) && n) {
		for (int i = 1; i <= n; i++) {
			scanf("%d", &height[i]);
		}
		height[0] = height[n + 1] = -1;
		for (int i = 1; i <= n; i++) {
			ll[i] = i;
			while (height[i] <= height[ll[i] - 1]) {
				ll[i] = ll[ll[i] - 1];
			}
		}
		for (int i = n; i >= 1; i--) {
			rr[i] = i;
			while (height[i] <= height[rr[i] + 1]) {
				rr[i] = rr[rr[i] + 1];
			}
		}
		LL ret = 0;
		for (int i = 1; i <= n; i++) {
			LL temp = (LL)height[i] * (rr[i] - ll[i] + 1);
			ret = max(ret, temp);
		}
		cout << ret << endl;
	}
	return 0;
}

