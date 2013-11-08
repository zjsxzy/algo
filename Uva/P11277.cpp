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

const int maxn = 55;
const double eps = 1e-8;
const double PI = acos(-1.0);
int n;
double len[55];

double calc(double r, double l) {
	double cosang = (r * r * 2 - l * l) / (2 * r * r);
	return acos(cosang);
}

double sum(double radius) {
	double ang = 0;
	for (int i = 0; i < n; i++) {
		double l = len[i];
		ang += calc(radius, l);
	}
	return ang;
}

double getArea(double a, double b, double c) {
	double p = 0.5 * (a + b + c);
	return sqrt(p * (p - a) * (p - b) * (p - c));
}

int main() {
	int Test;
	scanf("%d", &Test);
	for (; Test--; ) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%lf", &len[i]);
		}

		//inside 
		double lo = 0, hi = 1e10, radius = -1.0;
		while (hi - lo > eps) {
			double mid = (lo + hi) / 2;
			double temp = sum(mid);
			if (sig(temp - 2.0 * PI) == 0) radius = mid;
			if (temp <= 2.0 * PI) {
				hi = mid;
			} else {
				lo = mid;
			}
		}
		double area1 = 0.0;
		if (radius > 0) {
			for (int i = 0; i < n; i++) {
				area1 += 0.5 * radius * radius * calc(radius, len[i]);
			}
		}

		lo = 0.0, hi = 1e10, radius = -1.0;
		while (hi - lo > eps) {
			double mid = (lo + hi) / 2;
			double temp = sum2(mid);
			if (sig(temp - 2.0 * PI) == 0) radius = mid;
			if (temp <= 2.0 * PI) {
				hi = mid;
			} else {
				lo = mid;
			}
		}
		double area2 = 0.0;
		if (radius > 0) {
			double mx = 0.0;
			for (int i = 0; i < n; i++) {
				mx = max(mx, calc(radius, len[i]));
			}
			area2 = 0.5 * radius * radius * ()
		}

		printf("%.3f\n", area);
	}
	return 0;
}
