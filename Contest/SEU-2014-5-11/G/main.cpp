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

const double eps = 1e-8;
double X1, X2, Y1, Y2, vx, vy, V;
int main() {
	int ts;
	scanf("%d", &ts);
	while (ts--) {
		scanf("%lf%lf%lf%lf%lf%lf%lf", &X1, &Y1, &X2, &Y2, &vx, &vy, &V);
		double dx = X1 - X2, dy = Y1 - Y2;
		double a = vx * vx + vy * vy - V * V;
		double b = 2.0 * (vx * dx + vy * dy);
		double c = dx * dx + dy * dy;
		double delta = b * b - 4 * a * c;
		if (abs(a) < eps) {
			double t = -(c / b);
			if (t < 0) {
				printf("(0,0)\n");
			} else {
				double x3 = X1 + vx * t, y3 = Y1 + vy * t;
				dx = x3 - X2; dy = y3 - Y2;
				double len = sqrt(dx * dx + dy * dy);
				dx /= len;
				dy /= len; 
				printf("(%.6f,%.6f)\n", dx, dy);
			}
			continue;
		}
		if (delta < 0) {
			printf("(0,0)\n");
		} else {
			double t1 = (-b - sqrt(delta)) / a / 2.0, t2 = (-b + sqrt(delta)) / a / 2.0;
			double t;
			if (t1 < 0 && t2 < 0) {
				printf("(0,0)\n");
				continue;
			} else if (t1 < 0 && t2 >= 0) {
				t = t2;
			} else if (t2 < 0 && t1 >= 0) {
				t = t1;
			} else {
				t = min(t1, t2);
			}
			//printf("%.6f %.6f %.6f %.6f\n", a, b, c, t);
			double x3 = X1 + vx * t, y3 = Y1 + vy * t;
			dx = x3 - X2; dy = y3 - Y2;
			double len = sqrt(dx * dx + dy * dy);
			dx /= len;
			dy /= len; 
			printf("(%.6f,%.6f)\n", dx, dy);
		}
	}
	return 0;
}

