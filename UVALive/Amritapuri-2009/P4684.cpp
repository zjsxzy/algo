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
const LL inf = 1LL << 60;
const double eps = 1e-6;
int sig(double d) {
	return (d > eps) - (d < -eps);
}
struct Point {
	LL val;
	double x, y, ang;
	Point() {}
	Point(LL val, double x, double y) : val(val), x(x), y(y) {}
	void getAng() {
		ang = atan2(y, x);
	}
	bool operator < (const Point &pt) const {
		return ang < pt.ang;
	}
}tp[maxn];
int n;
LL a[maxn];
LL f[maxn], g[maxn];

int main() {
	int ts;
	scanf("%d", &ts);
	while (ts--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			int val; double x, y;
			scanf("%d%lf%lf", &val, &x, &y);
			tp[i] = Point(val, x, y);
			tp[i].getAng();
		}
		sort(tp, tp + n);
		int m = 0;
		memset(a, 0, sizeof(a));
		a[++m] = tp[0].val;
		for (int i = 1; i < n; i++)
			if (sig(tp[i].ang - tp[i - 1].ang) != 0)
				a[++m] = tp[i].val;
			else a[m] += tp[i].val;
		/*
		for (int i = 1; i <= n; i++)
			cout << a[i] << " ";
		cout << endl;
		*/
		
		f[0] = -inf;
		g[0] = inf;
		LL sum = 0, mx = -inf, mn = inf;
		for (int i = 1; i <= m; i++) {
			f[i] = max(a[i], f[i - 1] + a[i]);
			g[i] = min(a[i], g[i - 1] + a[i]);
			sum += a[i];
			mx = max(mx, f[i]);
			mn = min(mn, g[i]);
		}
		if (mn == sum) {
			cout << max(0LL, mx) << endl;
		} else {
			cout << max(0LL, max(mx, sum - mn)) << endl;
		}
	}
	return 0;
}

