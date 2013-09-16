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
double area(Point * p, int n) {
	double res = 0;
	p[n] = p[0];
	for(int i = 0; i < n; i ++) {
		res += p[i].x*p[i+1].y - p[i+1].x*p[i].y;
	}
	return res / 2;
}

Point ps[maxn];
double ang[maxn];
int n;
void init() {
	if(area(ps, n) < 0)	reverse(ps, ps+n);
	rotate(ps, min_element(ps, ps+n), ps+n);
	for(int i = 1; i < n; i ++) {
		ang[i] = atan2(ps[i].y-ps[0].y, ps[i].x-ps[0].x);
	}
	ang[0] = -M_PI/2;
}
bool dcmp(double a, double b) {
	return sig(a-b) < 0;
}
//0 外 2 内 1 边上
int judge(Point p) {
	if(onSeg(p, ps[0], ps[1]) || onSeg(p, ps[0], ps[n-1]))	return 1;
	int idx = lower_bound(ang, ang+n, atan2(p.y-ps[0].y, p.x-ps[0].x), dcmp) - ang;
	if(idx <= 1 || idx == n)	return 0;	//外面！
	return 1 + sig(cross(ps[idx-1], ps[idx], p));
}
int inside_convex(Point * ps, int n, Point q) {
	bool s[3] = {1, 1, 1};
	ps[n] = ps[0];
	for(int i = 0; i < n && (s[0] | s[2]); i ++) {
		s[ 1+sig(cross(ps[i+1], q, ps[i])) ] = 0;
	}
	if(s[0] | s[2])	return s[1]+1;	//里面或者边上
	return 0;
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
		//init();
		while (m--) {
			Point p;
			scanf("%lf%lf", &p.x, &p.y);
			if (inside_convex(ps, n, p) == 0) {
				printf("Outside\n");	
			} else {
				printf("Within\n");
			}
		}
	}
	return 0;
}
