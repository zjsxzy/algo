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

const int MAXN = 1005;
const double eps = 1e-8;
int sig(double d) {
	return (d > eps) - (d < -eps);
}
const double pi = 3.141;
double x[MAXN], y[MAXN];
double S;
int n;

bool inside(double px, double py, double cx, double cy, double radius) {
	double dist = (px - cx) * (px - cx) + (py - cy) * (py - cy);
	return dist <= radius + eps;
}

int main(int argc, char const *argv[])
{
	int cas = 1;
	while (scanf("%d", &n) && n) {
		printf("%d. ", cas++);
		scanf("%lf%lf%lf%lf%lf", &x[n], &y[n], &x[n + 1], &y[n + 1], &S);
		for (int i = 0; i < n; i++) {
			scanf("%lf%lf", &x[i], &y[i]);
		}
		int ret = n;
		for (int i = 0; i <= n; i++) {
			double r1 = (x[i] - x[n]) * (x[i] - x[n]) + (y[i] - y[n]) * (y[i] - y[n]);
			double s1 = r1 * pi;
			if (s1 > S + eps) continue;
			double s2 = S - s1 + eps, r2 = s2 / pi;
			int cnt = 0;
			for (int j = 0; j < n; j++) {
				if (inside(x[j], y[j], x[n], y[n], r1) || inside(x[j], y[j], x[n + 1], y[n + 1], r2))
					cnt++;
			}
			ret = min(ret, n - cnt);
		}
		printf("%d\n", ret);
	}
	return 0;
}