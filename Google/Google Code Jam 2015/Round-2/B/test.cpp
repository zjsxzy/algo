#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
#define MP(a, b) make_pair(a, b)
#define FOREACH(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)

const int maxn = 100 + 5;
const double eps = 1e-6;
int n;
double V, C, rate[maxn], x[maxn];

int sig(double x) {
	return abs(x) <= eps ? 0 : (x > 0 ? 1 : -1);
}

int main() {
//freopen("in", "r", stdin);
//freopen("B-small-attempt3.in", "r", stdin);
//freopen("B-small-attempt3.out", "w", stdout);
//freopen("A-large.in", "r", stdin);
//freopen("A-large.out", "w", stdout);
	int test;	scanf("%d", &test);
	for (int ti = 1; ti <= test; ti++) {
		scanf("%d %lf %lf", &n, &V, &C);
		for (int i = 0; i < n; i++)
			scanf("%lf %lf", rate + i, x + i);
		if (n == 2 && sig(x[0] - x[1]) == 0) {
			n = 1;
			rate[0] += rate[1];
		}

		printf("Case #%d: ", ti);
		if (n == 1) {
			if (sig(C - x[0]) == 0) {
				printf("%.12f\n", V / rate[0]);
			} else {
				puts("IMPOSSIBLE");
			}
		} else {
			double v0 = (C - x[1]) * V / (x[0] - x[1]);
			double v1 = V - v0;
			if (sig(v0) >= 0 && sig(v1) >= 0) {
				double tt = max(v0 / rate[0], v1 / rate[1]);
				printf("%.12f\n", tt);
			} else {
				puts("IMPOSSIBLE");
			}
		}
	}
	return 0;
}
