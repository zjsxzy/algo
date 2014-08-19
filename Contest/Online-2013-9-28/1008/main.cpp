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
const double eps = 1e-8;
const double PI = acos(-1.0);
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
	double dist(const Point &pt) {
		return sqrt((x - pt.x) * (x - pt.x) + (y - pt.y) * (y - pt.y));
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

const int maxn = 1005;
Point st;
double R;
Point ps[maxn];
int n;

struct node {
	double ang;
	int flag;
	node() {}
	node(double ang, int flag) : ang(ang), flag(flag) {}
	bool operator < (const node &pt) const {
		if (sig(ang - pt.ang) != 0) return sig(ang - pt.ang) < 0;
		return flag < pt.flag;
	}
}vec[maxn * 4];

double fit(double angle) {
	if (sig(angle) < 0) return angle += 2.0 * PI;
	if (sig(angle - 2.0 * PI) > 0) return angle -= 2.0 * PI;
	return angle;
}

void work() {
	double ret = 0;
	bool find = false;
	for (int i = 0; i <= n; i++) {
		int len = 0;
		//vector<pair<double, int> > vec;
		for (int j = 0; j <= n; j++) {
			if (i == j) continue;
			double d = ps[i].dist(ps[j]) / 2.0;
			if (sig(d - R) > 0) continue;
			double alpha = fit(atan2(ps[j].y - ps[i].y, ps[j].x - ps[i].x));
			double theta = acos(d / R);
			double ang1 = fit(alpha - theta);
			double ang2 = fit(alpha + theta);

			if (sig(ang1 - ang2) > 0) {
				vec[len++] = node(0, 0);
				vec[len++] = node(ang2, 1);
				vec[len++] = node(ang1, 0);
				vec[len++] = node(2.0 * PI, 1);
				//vec.PB(MP(0, 0));
				//vec.PB(MP(ang2, 1));
				//vec.PB(MP(ang1, 0));
				//vec.PB(MP(2.0 * PI, 1));
			} else {
				vec[len++] = node(ang1, 0);
				vec[len++] = node(ang2, 1);
				//vec.PB(MP(ang1, 0));
				//vec.PB(MP(ang2, 1));
			}

		}
		//sort(vec.begin(), vec.end());
		sort(vec, vec + len);
		int cnt = 0, Max = 0;
		//for (vector<pair<double, int> >::iterator it = vec.begin(); it != vec.end(); it++) {
		for (int j = 0; j < len; j++) {
			//if (it->second == 0) cnt++;
			if (vec[j].flag == 0) cnt++;
			else cnt--;
			Max = max(Max, cnt);
			if (Max + 1 == n + 1) {
				find = true;
			}
		}
	}
	if (!find) puts("X");
	else printf("%.2f\n", ret);
}

Point Find_Center(Point p1, Point p2)
{
	Point p3, center, mid;
	double b, c, ang;
	p3.x = p2.x - p1.x;
	p3.y = p2.y - p1.y;
	mid.x = (p1.x + p2.x) / 2;
	mid.y = (p1.y + p2.y) / 2;
	b = dis(p1, mid);
	c = sqrt(R * R - b * b);
	if (fabs(p3.y) < eps)
	{
		center.x = mid.x;
		center.y = mid.y + c;
	}
	else
	{
		ang = atan(-p3.x / p3.y);
		center.x = mid.x + c * cos(ang);
		center.y = mid.y + c * sin(ang);
	}
	return center;
}

Point Find_Center2(Point p1, Point p2)
{
	Point p3, center, mid;
	double b, c, ang;
	p3.x = p2.x - p1.x;
	p3.y = p2.y - p1.y;
	mid.x = (p1.x + p2.x) / 2;
	mid.y = (p1.y + p2.y) / 2;
	b = dis(p1, mid);
	c = sqrt(R * R - b * b);
	if (fabs(p3.y) < eps)
	{
		center.x = mid.x;
		center.y = mid.y + c;
	}
	else
	{
		ang = atan(-p3.x / p3.y);
		center.x = mid.x - c * cos(ang);
		center.y = mid.y - c * sin(ang);
	}
	return center;
}


void solve() {
	double res = 1e30;
	for (int i = 0; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (dis(ps[i], ps[j]) > 2.0 * R) continue;

			Point center = Find_Center(ps[i], ps[j]);
			bool flag = true;
			for (int k = 0; k < n; k++) {
				if (dis(center, ps[k]) > R) {
					flag = false;
					break;
				}
			}
			if (flag) {
				res = min(res, dis(ps[0], center));
			}

			center = Find_Center2(ps[i], ps[j]);
			flag = true;
			for (int k = 0; k < n; k++) {
				if (dis(center, ps[k]) > R) {
					flag = false;
					break;
				}
			}
			if (flag) {
				res = min(res, dis(ps[0], center));
			}
		}
	}
	if (res > 1e20) puts("X");
	else printf("%.2f\n", res);
}

int main() {
	while (~scanf("%lf%lf%lf", &ps[0].x, &ps[0].y, &R)) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%lf%lf", &ps[i].x, &ps[i].y);
		}
		solve();
	}
	return 0;
}