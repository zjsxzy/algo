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
//点到线段ab的距离
double PointToSeg(const Point &o, const Point &a, const Point &b) {
	if (sig(dot(o - a, b - a)) <= 0) return dis(o, a);
	if (sig(dot(o - b, a - b)) <= 0) return dis(o, b);
	return cross(o - a, b - a).len() / dis(a, b);
}
//判断三点共线
bool sameLine(const Point & a, const Point & b, const Point & c) {
	return sig(cross(a, b, c).len())==0;
}
//判断四点共面
bool sameFace(const Point & a, const Point & b, const Point & c, const Point & d) {
	return sig(dot(b-a, cross(a, c, d))) == 0;
}
//p绕着se向量，逆时针转ang角度
Point rotate(Point p, Point s, Point e, double ang) {
	if(sameLine(p, s, e)) {
		//sprintf("keke..\n");	error!
		return p;
	}
	Point fa1 = cross(s, e, p);
	Point fa2 = cross(e-s, fa1);
	
	double len = fabs(cross(p, e, s).len() / dis(e, s));	//圆心角
	fa2 = fa2.resize(len);
	fa1 = fa1.resize(len);
	Point h = p + fa2;
	Point pp = h + fa1;
	
	Point res = h + (p-h)*cos(ang) + (pp-h)*sin(ang);
	return res;
}
//vec是一个向量，将vec转到z轴向量，返回p点所转到的位置
Point rotate(Point p, Point vec) {
	Point z(0, 0, 1);
	Point fa = cross(vec, z);
	return rotate(p, Point(0,0,0), fa, acos( dot(z,vec)/vec.len() ));
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
double dis(const Point & a, const Point & b, const Point & c, const Point & d) {
	Point fa = cross(b-a,d-c);
	if(fa.len() == 0) {	//两直线平行
		return cross(c, a, b).len() / dis(a, b);
		//return dis(c, a, b);		//或者用这个，点到直线距离
	} else {
		return fabs(dot(c-a, fa) / fa.len());
	}
}

int n;
struct Cylinder {
	Point center, p1, p2, fp;
	double radius;
	void input() {
		center.input();
		p1.input();
		p2.input();
		radius = dis(center, p1);
		fp = cross(p1, p2, center) + center;
	}
}c[33];
double dis(const Cylinder &c1, const Cylinder &c2) {
	double d = dis(c1.center, c1.fp, c2.center, c2.fp);
	if (sig(d - (c1.radius + c2.radius)) <= 0) return -1;
	return d - (c1.radius + c2.radius);
}

int main(int argc, char const *argv[])
{
	int Test;
	scanf("%d", &Test);
	while (Test--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			c[i].input();
		double ret = 1e90;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				double temp = dis(c[i], c[j]);
				if (temp < ret) ret = temp;
			}
		}
		if (ret < 0) printf("Lucky\n");
		else printf("%.2f\n", ret);
	}
	return 0;
}