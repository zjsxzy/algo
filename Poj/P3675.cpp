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
#include <limits.h>
using namespace std;
#define PB push_back
#define MP make_pair
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
#define FOREACH(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
typedef long long LL;

double my_sqrt(double d) {return sqrt(max(d, 0.0));}
double my_acos(double d) {return acos(d<-1?-1:d>1?1:d);}
#define sqr(v) ((v)*(v))
const double eps = 1E-6;
const double PI = acos(-1.0);
int sig(double d) {
	return (d>eps) - (d<-eps);
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
	Point resize(double d) {
		d /= my_sqrt(sqr(x)+sqr(y));
		return Point(x*d, y*d);
	}
	Point left90() {
		return Point(-y, x);
	}
	Point rotate(double radian) {	//逆时针转
		double c = cos(radian), s = sin(radian);
		return Point(x*c-y*s, y*c+x*s);
	}
	double mod() {
		return my_sqrt(sqr(x)+sqr(y));
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
double dis(Point a, Point b) {
	return my_sqrt(sqr(a.x-b.x) + sqr(a.y-b.y));
}
double area(Point * p, int n) {
	double res = 0;
	p[n] = p[0];
	for(int i = 0; i < n; i ++) {
		res += p[i].x*p[i+1].y - p[i+1].x*p[i].y;
	}
	return res / 2;
}

//圆与线段交，交点加入ret中
void circle_cross_line(Point a, Point b, Point o, double r, vector<Point> &ret) {
	double x0 = o.x, y0 = o.y;
	double x1 = a.x, y1 = a.y;
	double x2 = b.x, y2 = b.y;
	double dx = x2 - x1, dy = y2 - y1;
	double A = dx * dx + dy * dy;
	double B = 2 * dx * (x1 - x0) + 2 * dy * (y1 - y0);
	double C = sqr(x1 - x0) + sqr(y1 - y0) - sqr(r);
	double delta = B * B - 4 * A * C;
	if (sig(delta) >= 0) {
		double t1 = (-B - my_sqrt(delta)) / (2 * A);
		double t2 = (-B + my_sqrt(delta)) / (2 * A);
		if (sig(t1 - 1) <= 0 && sig(t1) >= 0) {
			ret.PB(Point(x1 + t1 * dx, y1 + t1 * dy));
		}
		if (sig(t2 - 1) <= 0 && sig(t2) >= 0) {
			ret.PB(Point(x1 + t2 * dx, y1 + t2 * dy));
		}
	}
}

//扇形区域面积
double sector_area(Point a, Point b, Point o, double r) {
	double theta = atan2(a.y - o.y, a.x - o.x) - atan2(b.y - o.y, b.x - o.x);
	while (theta <= 0) theta += 2 * PI;
	while (theta > 2 * PI) theta -= 2 * PI;
	theta = min(theta, 2 * PI - theta);
	return r * r * theta / 2;
}

//圆心与线段构成的区域面积
double CircleTrianlge(Point a, Point b, Point o, double radius) {
	vector<Point> p;
	int ina = sig(dis(a, o) - radius) < 0;
	int inb = sig(dis(b, o) - radius) < 0;
	if (ina) {
		if (inb) {
			return fabs(cross(o, a, b)) / 2.0;
		} else {
			circle_cross_line(a, b, o, radius, p);
			return sector_area(b, p[0], o, radius) + fabs(cross(o, a, p[0])) / 2.0;
	}
	} else {
		if (inb) {
			circle_cross_line(a, b, o, radius, p);
			return sector_area(p[0], a, o, radius) + fabs(cross(o, p[0], b)) / 2.0;
		} else {
			circle_cross_line(a, b, o, radius, p);
			if (p.size() == 2) {
				return sector_area(a, p[0], o, radius) + sector_area(p[1], b, o, radius) + fabs(cross(o, p[0], p[1]) ) / 2.0;
			} else {
				return sector_area(a, b, o, radius);
			}
		}
	}
}

void calc() {
	for (int i = 0; i < n; i++) {
		printf("%d", a[i]);
		cout << a[i] << endl;
	}
}

//圆与一般多边形面积交
double CirclePolygon(Point *ps, int n, Point o, double radius) {
	//保证逆时针
	if (area(ps, n) < 0) reverse(ps, ps + n);

	ps[n] = ps[0];
	double res = 0;
	for (int i = 0; i < n; i++) {
		int sgn = sig(ps[i].x * ps[i + 1].y - ps[i].y * ps[i + 1].x);
		if (sgn != 0) {
			res += sgn * CircleTrianlge(ps[i], ps[i + 1], o, radius);
		}
	}
	return res;
}

int main() {
	Point ps[55], o;
	o.x = o.y = 0;
	double radius;
	int n;
	while (~scanf("%lf%d", &radius, &n)) {
		for (int i = 0; i < n; i++) {
			scanf("%lf%lf", &ps[i].x, &ps[i].y);
		}
		double res = CirclePolygon(ps, n, o, radius);
		printf("%.2f\n", res);
	}
	return 0;
}
