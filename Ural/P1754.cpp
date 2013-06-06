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
const double eps = 1E-8;
int sig(double d) {
	return (d>eps) - (d<-eps);
}
struct Point {
	double x, y, z;
	Point(double x, double y, double z) : x(x), y(y), z(z) {}
	Point() {}
	Point operator + (const Point & p) const {
		return Point(x+p.x, y+p.y, z+p.z);
	}
	Point operator - (const Point & p) const {
		return Point(x-p.x, y-p.y, z-p.z);
	}
	Point operator * (const double & d) const {
		return Point(x*d, y*d, z*d);
	}
	Point resize(double d) {
		d /= sqrt(x*x+y*y+z*z);
		return Point(x*d, y*d, z*d);
	}
	double len() const {
		return sqrt(x*x+y*y+z*z);
	}
	bool operator < (const Point & p) const {
		return sig(x-p.x)!=0 ? x<p.x : sig(y-p.y)!=0 ? y<p.y : sig(z-p.z)<0;
	}
	bool operator == (const Point & p) const {
		return sig(x-p.x)==0 && sig(y-p.y)==0 && sig(z-p.z)==0;
	}
	void input() {
		scanf("%lf%lf%lf", &x, &y, &z);
	}
	void output() const {
		printf("x = %.2f, y = %.2f, z = %.2f\n", x, y, z);
	}
};
//点乘
double dot(const Point & a, const Point & b) {
	return a.x*b.x + a.y*b.y + a.z*b.z;
}
double dot(const Point & o, const Point & a, const Point & b) {
	return dot(a-o, b-o);
}
//叉乘
Point cross(const Point & a, const Point & b) {
	return Point(a.y*b.z-a.z*b.y, a.z*b.x-a.x*b.z, a.x*b.y-a.y*b.x);
}
Point cross(const Point & o, const Point & a, const Point & b) {
	return cross(a-o,b-o);
}
//两点距离
double dis(const Point & a, const Point & b) {
	return sqrt(sqr(a.x-b.x) + sqr(a.y-b.y) + sqr(a.z-b.z));
}
//点到直线距离
double dis(const Point & o, const Point & a, const Point & b) {
	return cross(o, a, b).len() / dis(a,b);
}
//返回o到ab直线的投影点, 对于o在ab上也适合
Point pointToLine(const Point & o, const Point & a, const Point & b) {
	Point fa = cross(o, a, b);	//oab的垂向量
	Point vec = cross(b-a, fa);	//vec为在oab平面上，且由o指向ab的一条向量
	return o + vec.resize(fa.len()/dis(a,b));
}
//判断三点共线
bool sameLine(const Point & a, const Point & b, const Point & c) {
	return sig(cross(a, b, c).len())==0;
}
//判断四点共面
bool sameFace(const Point & a, const Point & b, const Point & c, const Point & d) {
	return sig(dot(b-a, cross(a, c, d))) == 0;
}
struct Face {
	Point a, b, c;
	Face() {}
	Face(Point a, Point b, Point c) : a(a), b(b), c(c) {}
	Point fa() const {
		return cross(a, b, c);
	}
	bool same_side(Point q , Point  p){
		return sig ( dot(a - q, cross(q, b, c)) 
			* dot(a - p , cross(p, b, c)) ) > 0 ;
	}
	bool inFace(Point q) const {	//判断某点是否在该平面上
		return sameFace(a, b, c, q);
	}
	bool operator == (const Face & face) const {
		Point fa1 = fa();
		Point fa2 = face.fa();
		if(sig(cross(fa1,fa2).len())!=0)    return false;
		return inFace(face.a);
	}
};
double dis(const Face & f, const Point & p) {
	Point fa = f.fa();
	return fabs(dot(fa, f.a-p) / fa.len());
}

int main(int argc, char const *argv[])
{
	double m, h, H;
	double x[5], y[5];
	cin >> m >> h >> H;
	Point p[5];
	for (int i = 0; i < 5; i++) {
		cin >> p[i].x >> p[i].y;
		if (i == 0) p[i].z = h;
		else if (i == 4) p[i].z = H;
		else p[i].z = 0;
	}

	Face f1 = Face(p[1], p[2], p[3]);
	Face f2 = Face(p[1], p[2], p[4]);
	Face f3 = Face(p[1], p[3], p[4]);
	Face f4 = Face(p[2], p[3], p[4]);

	double radius = 1e30;	
	radius = min(radius, dis(f1, p[0]));
	radius = min(radius, dis(f2, p[0]));
	radius = min(radius, dis(f3, p[0]));
	radius = min(radius, dis(f4, p[0]));

	printf("%s\n", sig(radius + h - m) <= 0 ? "YES" : "NO");
	return 0;
}