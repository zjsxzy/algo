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
#include <limits.h>
using namespace std;
#define PB push_back
#define MP make_pair
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
#define FOREACH(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
typedef long long LL;

int main() {
	int Test;
	scanf("%d", &Test);
	for (int cas = 1; cas <= Test; cas++) {
		printf("Case #%d:", cas);
		int n;
		scanf("%d", &n);
		vector<int> x, y;
		vector<bool> b(n);
		for (int i = 0; i < n; i++) {
			int val;
			scanf("%d", &val);
			if (val % 2 == 0) {
				b[i] = 1;
				x.PB(val);
			} else {
				y.PB(val);
			}
		}
		sort(x.begin(), x.end());
		sort(y.begin(), y.end());
		reverse(x.begin(), x.end());
		vector<int> res;
		int i = 0, j = 0;
		for (int k = 0; k < n; k++) {
			if (b[k]) {
				res.PB(x[i]);
				i++;
			} else {
				res.PB(y[j]);
				j++;
			}
		}
		for (int i = 0; i < res.size(); i++) {
			cout << " " << res[i];
		}
		cout << endl;
	}
	return 0;
}
