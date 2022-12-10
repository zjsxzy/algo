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

const double PI = acos(-1.0);
int n;
double x[2], y[2], z[2], radius[2];
#define sqr(x) ((x)*(x))

double vol_sphere(double radius) {
	return 4.0/3.0 * PI * radius * radius * radius;
}

double vol_spherical_cap(double radius, double h) {
	return PI * h * h * (radius - h / 3.0);
}

int main(int argc, char const *argv[])
{
	int Test;
	scanf("%d", &Test);
	while (Test--) {
		scanf("%lf%lf%lf%lf%lf%lf%lf%lf", x+0, y+0, z+0, radius+0, x+1, y+1, z+1, radius+1);
		double dist = sqrt(sqr(x[0]-x[1]) + sqr(y[0]-y[1]) + sqr(z[0] - z[1]));
		double ret = 0;
		if (dist >= radius[0] + radius[1]) {
			ret = vol_sphere(radius[0]) + vol_sphere(radius[1]);
		} else if (dist <= abs(radius[0] - radius[1])) {
			if (radius[0] <= radius[1]) {
				ret = vol_sphere(radius[1]);
			} else {
				ret = vol_sphere(radius[0]);
			}
		} else {
			double temp = (sqr(radius[0]) - sqr(radius[1])) / dist;
			double x = (dist + temp) / 2;
			double y = (dist - temp) / 2;
			ret += vol_sphere(radius[0]) - vol_spherical_cap(radius[0], radius[0] - x);
			ret += vol_sphere(radius[1]) - vol_spherical_cap(radius[1], radius[1] - y);
		}
		printf("%.2f\n", ret);
	}
	return 0;
}