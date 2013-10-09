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
	int Test;
	scanf("%d", &Test);
	for (int cas = 1; cas <= Test; cas++) {
		printf("Case %d: ", cas);
		int n;
		scanf("%d", &n);
		vector<int> a(n);
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		LL x = 0, y = 0;
		for (int i = 1; i < n; i++) {
			if (a[i] > a[i - 1]) x += a[i] - a[i - 1];
			else y += a[i - 1] - a[i];
		}
		cout << max(x, y) << " " << max(x, y) - min(x, y) + 1 << endl;
	}
	return 0;
}
