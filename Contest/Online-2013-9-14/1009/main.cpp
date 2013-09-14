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

const double PI = acos(-1.0);
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
double getArea(Point p0, Point p1, Point p2) {
	double res = 0;
	res =  p0.x * p1.y + p1.x * p2.y + p2.x * p0.y - p1.x * p0.y - p2.x * p1.y - p0.x * p2.y;
	return res / 2;
}

const int maxn = 10005;
int n, m;
Point ps[maxn], q[maxn];
Point center, small;
double sum[maxn];

double work(double l) {
	int lo = 1, hi = n, res = -1;
	while (lo <= hi) {
		int mid = (lo + hi) >> 1;
		if (sum[mid] >= l) {
			res = mid;
			hi = mid - 1;
		} else lo = mid + 1;
	}
	Point a = ps[0];
	Point b = ps[res - 1] + (ps[res] - ps[res - 1]).resize(l - sum[res - 1]);
	Point oa = a - center, ob = b - center;
	double cosang = (oa.x * ob.x + oa.y * ob.y) / oa.mod() / ob.mod();
	double ang = acos(cosang);
	if (l * 2 >= sum[n]) return 180.0 / PI * (2 * PI - ang);
	else return 180.0 / PI * ang;
}

int main() {
	int Test;
	scanf("%d", &Test);
	for (int cas = 1; cas <= Test; cas++) {
		printf("Case #%d:\n", cas);
		scanf("%d", &n);
		center.x = center.y = 0;
		int right = 0;
		for (int i = 0; i < n; i++) {
			scanf("%lf%lf", &q[i].x, &q[i].y);
			if (q[i].x > q[right].x) {
				right = i;
			}
		}
		double area = 0;
		double sum_area = 0;
		Point p0, p1, p2;
		p0 = q[0]; p1 = q[1];
		for (int i = 2; i < n; i++) {
			p2 = q[i];
			area = getArea(p0, p1, p2);
			sum_area += area;
			center.x += (p0.x + p1.x + p2.x) * area;
			center.y += (p0.y + p1.y + p2.y) * area;
			p1 = p2;
		}
		center.x = center.x / sum_area / 3;
		center.y = center.y / sum_area / 3;

		int j = 0;
		right++;
		for (int i = right; i < n; i++, j++) {
			ps[j] = q[i];
		}
		for (int i = 0; i < right; i++, j++) {
			ps[j] = q[i];
		}
		ps[n] = ps[0];
		
		memset(sum, 0, sizeof(sum));
		for (int i = 1; i <= n; i++) {
			sum[i] = sum[i - 1] + dis(ps[i], ps[i - 1]);
		}

		scanf("%lf%lf", &small.x, &small.y);
		scanf("%d", &m);
		while (m--) {
			double l;
			scanf("%lf", &l);
			int res = (int)(1.0 * l / sum[n]);
			l -= res * sum[n];
			double ang = work(l);
			printf("%.3f\n", res * 360.0 + ang);
		}
	}
	return 0;
}
