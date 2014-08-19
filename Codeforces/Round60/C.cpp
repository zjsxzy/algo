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
const double eps = 1E-12;
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
//点到线段ab的距离
double PointToSeg(const Point &o, const Point &a, const Point &b) {
	if (sig(dot(o - a, b - a)) <= 0) return dis(o, a);
	if (sig(dot(o - b, a - b)) <= 0) return dis(o, b);
	return cross(o - a, b - a).len() / dis(a, b);
}

const int maxn = 10005;
int n;
Point ps[maxn], tp;
double Vs, Vp;
double sum[maxn];

bool check(int idx) {
	return sig(dis(ps[idx], tp) / Vp - sum[idx] / Vs) <= 0;
}

int main(int argc, char const *argv[])
{
	cin >> n;
	for (int i = 0; i <= n; i++) {
		cin >> ps[i].x >> ps[i].y >> ps[i].z;
	}
	cin >> Vp >> Vs;
	cin >> tp.x >> tp.y >> tp.z;

	for (int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + dis(ps[i - 1], ps[i]);

	int lo = 1, hi = n, ret = -1;
	while (lo <= hi) {
		int mid = (lo + hi) >> 1;
		if (check(mid)) {
			hi = mid - 1;
			ret = mid;
		} else lo = mid + 1;
	}
	if (ret == -1) cout << "NO" << endl;
	else {
		cout << "YES" << endl;
		Point a = ps[ret - 1], b = ps[ret];
		double curtime = sum[ret - 1] / Vs;
		double lo = 0, hi = 1, k;
		Point temp;
		while (hi - lo > eps) {
			double mid = (lo + hi) / 2;
			temp = a + (b - a) * mid;
			if (sig(dis(temp, tp) / Vp - (curtime + dis(a, temp) / Vs)) <= 0) hi = mid;
			else lo = mid;
		}
		printf("%.9f\n", dis(temp, tp) / Vp);
		printf("%.9f %.9f %.9f\n", temp.x, temp.y, temp.z);
	}
	return 0;
}
