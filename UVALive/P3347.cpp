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

int n;
double x[105], y[105], z[105];
#define sqsum(x, y, z) ((x)*(x) + (y)*(y) + (z)*(z))

int main(int argc, char const *argv[])
{
	while (scanf("%d", &n) && n) {
		for (int i = 0; i < n; i++) {
			scanf("%lf%lf%lf", x + i, y + i, z + i);
		}

		double x0 = 0, y0 = 0, lambda = 1;
		int iter = 3000 * n;
		for (int k = 0; k < iter; k++) {
			int i_opt;
			double d_opt = -1;
			for (int i = 0; i < n; i++) {
				double d = sqsum(x[i] - x0, y[i] - y0, z[i]);
				if (d_opt < d) {
					d_opt = d;
					i_opt = i;
				}
			}
			x0 += lambda * (x[i_opt] - x0);
			y0 += lambda * (y[i_opt] - y0);
			lambda *= 0.999;
		}
		printf("%.3f %.3f\n", x0, y0);
	}
	return 0;
}