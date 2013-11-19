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

double my_sqrt(double d) {return sqrt(max(d, 0.0));}
double my_acos(double d) {return acos(d<-1?-1:d>1?1:d);}
#define sqr(v) ((v)*(v))
const double eps = 1E-9;
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
	void input() {
		scanf("%lf%lf", &x, &y);
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
	//if(sig(s1)==0 && sig(s2)==0)	return 2;
	if(sig(s2-s1)==0)	return 0;
	p.x = (c.x*s2-d.x*s1)/(s2-s1);
	p.y = (c.y*s2-d.y*s1)/(s2-s1); 
	return 1;
}
double bet(double p, double a, double b) {
	return sig(p - a) >= 0 && sig(p - b) <= 0;
}
//判断p是否在线段ab上，在端点处也返回true
bool onSeg(Point p, Point a, Point b) {
	return bet(p.x, min(a.x, b.x), max(a.x, b.x)) && bet(p.y, min(a.y, b.y), max(a.y, b.y));
	//return sig(cross(p, a, b))==0 && sig(dot(p, a, b))<=0;
}
bool onRay(Point p, Point a, Point b) {
	return sig(dot(a, b, p)) >= 0;
}

Point pA[3], pB[3];
Point vA, vB;

int main() {
	int ts;
	scanf("%d", &ts);
	while (ts--) {
		pA[0].input(); pA[1].input(); pA[2].input(); vA.input();
		pB[0].input(); pB[1].input(); pB[2].input(); vB.input();

		double res = 1e100;
		// Case 1
		Point vec = vA - vB; // vB = 0
		if (sig(vec.mod()) == 0) {
			puts("NO COLLISION");
			continue;
		}
		for (int i = 0; i < 3; i++) {
			Point tp = pA[i];
			for (int j = 0; j < 3; j++) {
				Point a = pB[j], b = pB[(j + 1) % 3];
				Point intersect;
				int flag = lineCross(tp, tp + vec, a, b, intersect);
				if (flag) {
					if (onSeg(intersect, a, b) && onRay(intersect, tp, tp + vec)) {
						double temp = (intersect - tp).mod() / vec.mod();
						if (sig(temp - res) < 0) res = temp;
					}
				}
			}
		}

		// Case 2
		vec = vB - vA; // vA = 0
		for (int i = 0; i < 3; i++) {
			Point tp = pB[i];
			for (int j = 0; j < 3; j++) {
				Point a = pA[j], b = pA[(j + 1) % 3];
				Point intersect;
				int flag = lineCross(tp, tp + vec, a, b, intersect);
				if (flag) {
					if (onSeg(intersect, a, b) && onRay(intersect, tp, tp + vec)) {
						double temp = (intersect - tp).mod() / vec.mod();
						if (sig(temp - res) < 0) res = temp;
					}
				}
			}
		}

		if (res < 1e90) printf("%.9f\n", res);
		else puts("NO COLLISION");
	}
	return 0;
}
