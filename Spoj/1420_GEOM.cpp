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
const double eps = 1E-6;
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
	bool operator != (const Point & p) const {
		return sig(x - p.x) != 0 || sig(y - p.y) != 0;
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

Point A, B, C, D, P;

Point perpendicular(const Point &o, const Point &a, const Point &b) {
	double d = dis(a, b);
	double s = cross(a, b, o) / d;
	Point res = o + (a-b).left90()*(s/d);
	return res;
}

bool work(Point &ret) {
	Point pa = perpendicular(A, B, P);
	Point pb = perpendicular(B, C, P);
	Point pc = perpendicular(C, D, P);
	Point pd = perpendicular(D, A, P);
	set<Point> st;
	Point temp;
	if (A != pa && B != pb) {
		lineCross(A, pa, B, pb, temp);
		st.insert(temp);
	}
	if (A != pa && C != pc) {
		lineCross(A, pa, C, pc, temp);
		st.insert(temp);
	}
	if (A != pa && D != pd) {
		lineCross(A, pa, D, pd, temp);
		st.insert(temp);
	}
	if (B != pb && C != pc) {
		lineCross(B, pb, C, pc, temp);
		st.insert(temp);
	}
	if (B != pb && D != pd){
		lineCross(B, pb, D, pd, temp);
		st.insert(temp);
	}
	if (C != pc && D != pd) {
		lineCross(C, pc, D, pd, temp);
		st.insert(temp);
	}
	if (st.size() == 1) {
		ret = *st.begin();
		return true;
	} else {
		return false;
	}
}

double fit(double d) {
	return sig(d) == 0 ? 0.0 : d;
}

int main(int argc, char const *argv[])
{
	double x, y, len;
	while (~scanf("%lf%lf", &x, &y)) {
		scanf("%lf", &len);
		A = Point(x - len/2, y - len/2);
		B = Point(x - len/2, y + len/2);
		C = Point(x + len/2, y + len/2);
		D = Point(x + len/2, y - len/2);
		scanf("%lf%lf", &P.x, &P.y);
		Point ret;
		if (work(ret)) {
			puts("YES");
			printf("%.1f %.1f\n", fit(ret.x), fit(ret.y));
		} else {
			puts("NO");
		}
	}
	return 0;
}
