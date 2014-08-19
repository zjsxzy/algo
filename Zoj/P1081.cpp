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

const int maxn = 105;
#define sqr(x) ((x) * (x))
const double eps = 1e-8;
int sig(double d) {
	return (d > eps) - (d < -eps);
}
struct Point {
	double x, y;
	Point(double x, double y) : x(x), y(y) {}
	Point() {}
	Point operator - (const Point & p) const {
		return Point(x-p.x, y-p.y);
	}
	Point operator + (const Point & p) const {
		return Point(x+p.x, y+p.y);
	}
	Point operator * (double d) const {
		return Point(x*d, y*d);
	}
	/*double operator * (const Point &b) const {
		return x * b.y - y * b.x;
	}*/
	bool operator == (const Point & p) const {
		return sig(x-p.x)==0 && sig(y-p.y)==0;
	}
	bool operator < (const Point & p) const {
		return sig(x-p.x)!=0 ? x<p.x : sig(y-p.y)<0;
	}
	Point left90() {
		return Point(-y, x);
	}
	Point rotate(double radian) {	//逆时针转
		double c = cos(radian), s = sin(radian);
		return Point(x*c-y*s, y*c+x*s);
	}
	void output() {
		printf("x = %.2f, y = %.2f\n", x, y);
	}
};
double cross(const Point & o, const Point & a, const Point & b) {
	return (a.x-o.x)*(b.y-o.y) - (b.x-o.x)*(a.y-o.y);
}
double dot(Point o, Point a, Point b) {
	return (a.x-o.x)*(b.x-o.x) + (a.y-o.y)*(b.y-o.y);
}
bool onSeg(Point p, Point a, Point b) {
	return sig(cross(p, a, b))==0 && sig(dot(p, a, b))<=0;
}

Point ps[maxn];
double ang[maxn];
int n;

//判断点在一般多边形 外: 0 内: 1 边上: 2
int inside_polygon(Point *ps, Point p) {
	int num = 0;
	ps[n] = ps[0];
	for (int i = 0; i < n; i++) {
		if (onSeg(p, ps[i], ps[i + 1])) return 2;
		int k = sig(cross(ps[i], ps[i + 1], p));
		int d1 = sig(ps[i].y - p.y);
		int d2 = sig(ps[i + 1].y - p.y);
		if (k > 0 && d1 <= 0 && d2 > 0) num++;
		if (k < 0 && d2 <= 0 && d1 > 0) num--;
	}
	return num != 0;
}

int main() {
	int cas = 1;
	while (~scanf("%d", &n)) {
		if (n == 0) break;
		if (cas > 1) printf("\n");
		printf("Problem %d:\n", cas++);
		int m; scanf("%d", &m);
		for (int i = 0; i < n; i++) {
			scanf("%lf%lf", &ps[i].x, &ps[i].y);
		}
		while (m--) {
			Point p;
			scanf("%lf%lf", &p.x, &p.y);
			if (inside_polygon(ps, p) == 0) {
				printf("Outside\n");	
			} else {
				printf("Within\n");
			}
		}
	}
	return 0;
}
