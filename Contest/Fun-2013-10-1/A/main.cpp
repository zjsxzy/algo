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

const int maxn = 100005;
struct node {
	int a, b;
	bool operator < (const node &pt) const {
		return a > pt.a;
	}
}p[maxn];
int n;

int main() {
	int Test;
	scanf("%d", &Test);
	for (int cas = 1; cas <= Test; cas++) {
		printf("Case %d: ", cas);
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d%d", &p[i].a, &p[i].b);
		}
		sort(p + 1, p + n + 1);
		LL res = 1ll << 60;
		int B = 0;
		p[n + 1].a = 0;
		for (int i = 1; i <= n; i++) {
			B = max(B, p[i - 1].b);
			res = min(res, (LL)p[i].a + B);
		}
		cout << res << endl;
	}
	return 0;
}
