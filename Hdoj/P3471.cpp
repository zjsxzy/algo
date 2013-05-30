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
Point intersect(const Face & f, const Point & a, const Point & b) {
	Point fa = f.fa();
	double t = dot(fa,f.a-a) / dot(fa,b-a);
	return a+(b-a)*t;
}

Point ps[10], st, ed, velocity;

void lose() {
	printf("Intelligent Larrionda!!!\n");
}

void win() {
	printf("Stupid Larrionda!!!\n");
}

bool inRec(const Point &o, const Point &fa) {
	Point p[5] = {ps[0], ps[1], ps[2], ps[3], ps[0]};
	int temp = sig(dot(cross(p[0], p[1], o), fa));
	for (int i = 1; i < 4; i++) {
		if (temp != sig(dot(cross(p[i], p[i + 1], o), fa))) {
			return false;
		}
	}
	return true;
}

int main(int argc, char const *argv[])
{
	int Test;
	scanf("%d", &Test); 
	for (int cas = 1; cas <= Test; cas++) {
		printf("Case %d: ", cas);
		st.input(); velocity.input();
		ed = st + velocity;
		for (int i = 0; i < 8; i++)
			ps[i].input();
		Face goal = Face(ps[0], ps[1], ps[2]);
		Point fa = goal.fa();

		//球不动
		if (sig(velocity.len()) == 0) {
			lose();
			continue;
		}
		//向球门外射
		if (sig(dot(velocity, fa)) <= 0) {
			lose();
			continue;
		}
		//球在内侧
		if (sig(dot(st - goal.a, fa)) > 0) {
			lose();
			continue;
		}

		Point tp = intersect(goal, st, st + velocity);
		if (inRec(tp, fa)) {
			win();
		} else {
			lose();
		}
	}
	return 0;
}