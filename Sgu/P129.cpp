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
	bool operator == (const Point & p) const {
		return sig(x-p.x)==0 && sig(y-p.y)==0;
	}
	bool operator < (const Point & p) const {
		return sig(x-p.x)!=0 ? x<p.x : sig(y-p.y)<0;
	}
	double mod() {
		return my_sqrt(sqr(x)+sqr(y));
	}
	Point resize(double d) {
		return Point(x * d, y * d);
	}
	void input() {
		scanf("%lf%lf", &x, &y);
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
//0不在里面	2在里面 1边上
int inside_convex(Point * ps, int n, Point q) {
	bool s[3] = {1, 1, 1};
	ps[n] = ps[0];
	for(int i = 0; i < n && (s[0] | s[2]); i ++) {
		s[ 1+sig(cross(ps[i+1], q, ps[i])) ] = 0;
	}
	if(s[0] | s[2])	return s[1]+1;	//里面或者边上
	return 0;
}
//判断p是否在线段ab上，在端点处也返回true
bool onSeg(Point p, Point a, Point b) {
	return sig(cross(p, a, b))==0 && sig(dot(p, a, b))<=0;
}
int graham(Point*p, int n, int*ch) {
#define push(x)     ch[len ++]=x
#define pop()		len --
	sort(p, p+n);
	int len = 0, len0 = 1, i;
	for(i = 0; i < n; i ++) {
		while(len > len0 && sig(cross(p[ch[len-1]], p[ch[len-2]], p[i]))<=0)
			pop();
		push(i);
	}
	len0 = len;
	for(i = n-2; i >= 0; i --) {
		while(len > len0 && sig(cross(p[ch[len-1]], p[ch[len-2]], p[i]))<=0)
			pop();
		push(i);
	}
	return len-1;
}

const int maxn = 400 + 5;
int n, n_hull;
int ch[maxn];
Point ps[maxn], qs[maxn];

double solve(const Point &a, const Point &b) {
	vector<Point> pVec;
	pVec.PB(a); pVec.PB(b);
	for (int i = 0; i < n_hull; i++) {
		Point p = qs[i], q = qs[(i + 1) % n_hull];
		Point inter;
		if (lineCross(a, b, p, q, inter) == 1 && onSeg(inter, a, b)) {
			if (inter == a || inter == b) continue;
			pVec.PB(inter);
		}
	}
	sort(pVec.begin(), pVec.end());
	double ret = 0;
	for (int i = 0; i < pVec.size() - 1; i++) {
		Point p = pVec[i], q = pVec[i + 1];
		Point mid = (p + q).resize(0.5);
		if (inside_convex(qs, n_hull, mid) == 2) {
			ret += dis(p, q);
		}
	}
	return ret;
}

int main() {
	while (~scanf("%d", &n)) {
		for (int i = 0; i < n; i++) {
			ps[i].input();
		}
		n_hull = graham(ps, n, ch);
		for (int i = 0; i < n_hull; i++)
			qs[i] = ps[ch[i]];
		int query;
		scanf("%d", &query);
		while (query--) {
			Point a, b;
			a.input(); b.input();
			double ret = solve(a, b);
			if (sig(ret) == 0) ret = 0;
			printf("%.2f\n", ret);
		}
	}
	return 0;
}
