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
bool sameFace(const Point & a, const Point & b, const Point & c, const Point & d) {
	return sig(dot(b-a, cross(a, c, d))) == 0;
}
//返回o到ab直线的投影点, 对于o在ab上也适合
Point pointToLine(const Point & o, const Point & a, const Point & b) {
	Point fa = cross(o, a, b);	//oab的垂向量
	Point vec = cross(b-a, fa);	//vec为在oab平面上，且由o指向ab的一条向量
	return o + vec.resize(fa.len()/dis(a,b));
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
//判断两直线平行
bool px(const Point & a, const Point & b, const Point & c, const Point & d) {
	return sig(cross(b-a, d-c).len()) == 0;
}
//求ab直线与f的交点，断言ab于f不平行
Point intersect(const Face & f, const Point & a, const Point & b) {
	Point fa = f.fa();
	double t = dot(fa,f.a-a) / dot(fa,b-a);
	return a+(b-a)*t;
}
//求两直线交点，【断言】两直线共面且不平行
Point intersect(const Point & a, const Point & b, const Point & c, const Point & d) {
	Point e = d + cross(a-b, c-d);
	return intersect(Face(c,d,e), a, b);
	//或者用下面代码：
	Point fa = cross(c, d, e);
	double t = dot(fa, c-a) / dot(fa, b-a);
	return a+(b-a) * t;
}
//判断某个点是否在线段上, 断言oab共线		-1表示在上面，0表示在线段边上，1表示在线段外
int onSeg(const Point & o, const Point & a, const Point & b) {
	return sig(dot(o, a, b));
}
//求两直线的共垂线, p1返回ab直线上的公垂线交点，p2返回cd直线上的公垂线交点
void gc(const Point & a, const Point & b, const Point & c, const Point & d, Point & p1, Point & p2) {
	Point e = d + cross(a-b, c-d);
	p1 = intersect(Face(c,d,e), a, b);
	p2 = pointToLine(p1, c, d);
}
//两直线距离
double dis(const Point & a, const Point & b, const Point & c, const Point & d) {
	Point fa = cross(b-a,d-c);
	if(fa.len() == 0) {	//两直线平行
		return cross(c, a, b).len() / dis(a, b);
		//return dis(c, a, b);		//或者用这个，点到直线距离
	} else {
		return fabs(dot(c-a, fa) / fa.len());
	}
}

Point p1, p2, p3, p4, v, org;
double d;
double get_min(double a, double b, double c, double d) {
	double ret = a;
	if (b < ret) ret = b;
	if (c < ret) ret = c;
	if (d < ret) ret = d;
	return ret;
}

double PointToSeg(const Point &o, const Point &a, const Point &b) {
	if (sig(dot(o - a, b - a)) <= 0) return dis(o, a);
	if (sig(dot(o - b, a - b)) <= 0) return dis(o, b);
	return cross(o - a, b - a).len() / dis(a, b);
}

int main(int argc, char const *argv[])
{
	while (~scanf("%lf%lf%lf", &p1.x, &p1.y, &p1.z)) {
		p2.input(); p3.input(); p4.input();
		org.input();
		scanf("%lf", &d);

		if (sig(dis(org, p1) - d) > 0) {
			p1 = org + (p1 - org).resize(d);
		}

		if (sig(dis(org, p2) - d) > 0) {
			p2 = org + (p2 - org).resize(d);
		}

		double ret;
		if (sameFace(p1, p2, p3, p4)) { // 共面
			if (px(p1, p2, p3, p4)) { // 平行
				ret = get_min(PointToSeg(p1, p3, p4), PointToSeg(p2, p3, p4), PointToSeg(p3, p1, p2), PointToSeg(p4, p1, p2));
				printf("%.3f\n", ret);
			} else { // 不平行
				Point tp = intersect(p1, p2, p3, p4);
				if (onSeg(tp, p1, p2) <= 0 && onSeg(tp, p3, p4) <= 0) { // 交点在线段上
					ret = 0;
					printf("%.3f\n", ret);
				} else { // 交点不在线段上
					ret = get_min(PointToSeg(p1, p3, p4), PointToSeg(p2, p3, p4), PointToSeg(p3, p1, p2), PointToSeg(p4, p1, p2));
					printf("%.3f\n", ret);
				}
			}
		} else { // 异面
			Point t1, t2;
			gc(p1, p2, p3, p4, t1, t2);
			if (onSeg(t1, p1, p2) <= 0 && onSeg(t2, p3, p4) <= 0) { // 公垂线交点在线段上
				ret = dis(p1, p2, p3, p4);
				printf("%.3f\n", ret);
			} else { // 公垂线交点不在线段上
				ret = get_min(PointToSeg(p1, p3, p4), PointToSeg(p2, p3, p4), PointToSeg(p3, p1, p2), PointToSeg(p4, p1, p2));
				printf("%.3f\n", ret);
			}
		}
	}
	return 0;
}