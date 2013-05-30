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
const double inf = 1e30;
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
bool onSeg(Point p, Point a, Point b) {
	return sig(cross(p, a, b))==0 && sig(dot(p, a, b))<=0;
}

struct Seg {
	Point st, ed;
	double k;

	Seg() {}
	Seg(Point st, Point ed) : st(st), ed(ed) {}

	bool operator < (const Seg &pt) const {
		sig(k - pt.k) == 0 ? st < pt.st : sig(k - pt.k) < 0;
	}

	void calc() {
		if (ed < st) swap(st, ed);
		if (sig(ed.x - st.x) == 0) k = inf;
		else k = (ed.y - st.y) / (ed.x - st.x);
	}

	bool same(const Seg &pt) {
		if (sig(k - pt.k) != 0) return false;
		return onSeg(pt.st, st, ed) || onSeg(pt.ed, st, ed);
	}

}s[10005];

int main(int argc, char const *argv[])
{
	int n;
	while (scanf("%d", &n) && n) {
		for (int i = 0; i < n; i++) {
			scanf("%lf%lf%lf%lf", &s[i].st.x, &s[i].st.y, &s[i].ed.x, &s[i].ed.y);
			s[i].calc();
		}
		sort(s, s + n);

		int ret = 1;
		Seg cur = s[0];
		for (int i = 1; i < n; i++) {
			if (cur.same(s[i])) {
				cur.st = min(cur.st, s[i].st);
				cur.ed = max(cur.ed, s[i].ed);
			} else {
				cur = s[i];
				ret++;
			}
		}
		printf("%d\n", ret);
	}
	return 0;
}