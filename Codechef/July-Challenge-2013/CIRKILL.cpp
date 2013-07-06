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

#define sqr(v) ((v)*(v))
double my_sqrt(double d) {return sqrt(max(d, 0.0));}
double my_acos(double d) {return acos(d<-1?-1:d>1?1:d);}
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
int lineCross(Point a, Point b, Point c, Point d, Point &p) {
	double s1, s2;
	s1=cross(a,b,c);
	s2=cross(a,b,d);
	if(sig(s1)==0 && sig(s2)==0)	return 2;
	if(sig(s2-s1)==0)	return 0;
	p.x = (c.x*s2-d.x*s1)/(s2-s1);
	p.y = (c.y*s2-d.y*s1)/(s2-s1); 
	return 1;
}
struct Circle {
	Point ori;
	double radius;

	Circle() {}
	Circle(Point pa, Point pb, Point pc) {
		Point mid1 = (pa + pb) * 0.5;
		Point t1 = mid1 + (mid1 - pa).rotate(PI / 2);
		Point mid2 = (pa + pc) * 0.5;
		Point t2 = mid2 + (mid2 - pa).rotate(PI / 2);
		lineCross(mid1, t1, mid2, t2, ori);
		radius = dis(ori, pa);
	}

	bool inside(const Point &tp) {
		double d = dis(ori, tp);
		return sig(d - radius) <= 0;
	}
};

Point ps[55];
int n;

int work() {
	int ret = 0;
	for (int a = 0; a < n; a++) {
		for (int b = a + 1; b < n; b++) {
			for (int c = b + 1; c < n; c++) {
				if (cross(ps[a], ps[b], ps[c]) == 0) continue;
				Circle cir = Circle(ps[a], ps[b], ps[c]);
				for (int i = 0; i < n; i++) {
					if (i == a || i == b || i == c) continue;
					if (cir.inside(ps[i])) {
						//ps[a].output(); ps[b].output(); ps[c].output(); 
						//ps[i].output();
						ret++;
					}
				}
			}
		}
	}
	return ret;
}

int main(int argc, char const *argv[])
{
	int Test;
	scanf("%d", &Test);
	while (Test--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%lf%lf", &ps[i].x, &ps[i].y);
		}
		int ret = work();
		int d = n * (n - 1) * (n - 2) * (n - 3) / 6;
		printf("%.8f\n", (double)ret / d);
	}
	return 0;
}