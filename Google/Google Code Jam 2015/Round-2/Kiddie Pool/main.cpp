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

const int MAXN = 100 + 5;
double x[MAXN], rate[MAXN];
const double eps = 1e-6;
int sig(double d) {
	return (d > eps) - (d < -eps);
}
int main() {
#ifndef ONLINE_JUDGE
	// freopen("in.txt", "r", stdin);
#endif
	int ts;	scanf("%d", &ts);
	int n;
	double V, C;
	for (int cas = 1; cas <= ts; cas++) {
		scanf("%d %lf %lf", &n, &V, &C);
		for (int i = 0; i < n; i++)
			scanf("%lf %lf", rate + i, x + i);
		if (n == 2 && fabs(x[0] - x[1]) < eps) {
			n = 1; rate[0] += rate[1];
		}
		printf("Case #%d: ", cas);
		if (n == 1) {
			if (fabs(C - x[0]) < eps) {
				printf("%.12f\n", V / rate[0]);
			} else {
				puts("IMPOSSIBLE");
			}
		} else {
			double t0 = (C - x[1]) * V / (x[0] - x[1]);
			double t1 = V - t0;
			if (sig(t0) >= 0 && sig(t1) >= 0) {
				printf("%.12f\n", max(t0 / rate[0], t1 / rate[1]));
			} else {
				puts("IMPOSSIBLE");
			}
		}
	}
	return 0;
}

