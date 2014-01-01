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
double area(Point * p, int n) {
	double res = 0;
	p[n] = p[0];
	for(int i = 0; i < n; i ++) {
		res += p[i].x*p[i+1].y - p[i+1].x*p[i].y;
	}
	return res / 2;
}
//多边形切割
//用直线ab切割多边形p，切割后的在向量(a,b)的左侧，并原地保存切割结果
//如果退化为一个点，也会返回去, 此时n为1
void polygon_cut(Point * p, int & n, Point a, Point b) {
	static Point pp[305];
	int m = 0;
	p[n] = p[0];
	for(int i = 0; i < n; i ++) {
		if(sig(cross(a, b, p[i])) > 0)
			pp[m ++] = p[i];
		if(sig(cross(a, b, p[i])) != sig(cross(a, b, p[i+1])))
			lineCross(a, b, p[i], p[i+1], pp[m ++]);
	}
	n = 0;
	for(int i = 0; i < m; i ++)
		if(!i || !(pp[i]==pp[i-1]))
			p[n ++] = pp[i];
	while(n>1 && p[n-1]==p[0])	n --;
}
const int MAXN = 300 + 5;
const double BOUND = 10000000.0;
int n, k;
double y[MAXN][MAXN];
Point p[MAXN];
double ans[MAXN];

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= k; j++) {
			scanf("%lf", &y[i][j]);
		}
		ans[i] = 0;
	}

	for (int x = 0; x < k; x++) {
		p[0] = Point(x, 0);
		p[1] = Point(x + 1, 0);
		p[2] = Point(x + 1, BOUND);
		p[3] = Point(x, BOUND);
		int m = 4;

		double last = area(p, m);
		for (int i = 0; i < n; i++) {
			polygon_cut(p, m, Point(x, y[i][x]), Point(x + 1, y[i][x + 1]));
			double cur = area(p, m);
			ans[i] += fabs(cur - last);
			last = cur;
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%.10f\n", ans[i]);
	}
	return 0;
}

