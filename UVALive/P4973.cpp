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
struct Point {
	LL x, y, z;
	Point(LL x, LL y, LL z) : x(x), y(y), z(z) {}
	Point() {}
	Point operator + (const Point & p) const {
		return Point(x+p.x, y+p.y, z+p.z);
	}
	Point operator - (const Point & p) const {
		return Point(x-p.x, y-p.y, z-p.z);
	}
	Point operator * (const LL & d) const {
		return Point(x*d, y*d, z*d);
	}
	LL len2() const {
		return x*x+y*y+z*z;
	}
	void input() {
		cin >> x >> y >> z;
	}
	void output() const {
		printf("x = %lld, y = %lld, z = %lld\n", x, y, z);
	}
};
//点乘
LL dot(const Point & a, const Point & b) {
	return a.x*b.x + a.y*b.y + a.z*b.z;
}
LL dot(const Point & o, const Point & a, const Point & b) {
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
LL dis2(const Point &a, const Point &b) {
	return (a - b).len2();
}

LL gcd(LL a, LL b) {
	return b == 0 ? a : gcd(b, a % b);
}
struct Frac {
	LL x, y;
	Frac() {}
	Frac(LL _x, LL _y) {
		LL g = gcd(_x, _y);
		x = _x / g; y = _y / g;
	}
	void output() {
		printf("%lld %lld\n", x, y);
	}
	bool operator < (const Frac &pt) const {
		return x * pt.y < y * pt.x;
	}
};

Point p1, p2, p3, p4;
Point v;

Frac get_min(Frac a, Frac b, Frac c, Frac d) {
	Frac ret = a;
	if (b < ret) ret = b;
	if (c < ret) ret = c;
	if (d < ret) ret = d;
	return ret;
}

bool check() {
	LL v1 = dot(cross(p3 - p4, v), p1 - p3);
	LL v2 = dot(cross(p3 - p4, v), p2 - p3);
	if (v1 * v2 >= 0) return false;

	v1 = dot(cross(p1 - p2, v), p3 - p1);
	v2 = dot(cross(p1 - p2, v), p4 - p1);
	if (v1 * v2 >= 0) return false;

	return true;
}

Frac get_dis(const Point &o, const Point &a, const Point &b) {
	if (dot(o - a, b - a) <= 0) return Frac(dis2(o, a), 1);
	if (dot(o - b, a - b) <= 0) return Frac(dis2(o, b), 1);
	return Frac(cross(o - a, b - a).len2(), dis2(a, b));
}

int main(int argc, char const *argv[])
{
	int Test;
	scanf("%d", &Test);
	while (Test--) {
		p1.input(); p2.input(); p3.input(); p4.input();
		v = cross(p1 - p2, p3 - p4);
		if (check()) {
			LL dot2 = dot(p3 - p1, v);
			dot2 *= dot2;
			Frac ret = Frac(dot2, v.len2());
			ret.output();
		} else {
			Frac ret = get_min(get_dis(p1, p3, p4), get_dis(p2, p3, p4), get_dis(p3, p1, p2), get_dis(p4, p1, p2));
			ret.output();
		}
	}
	return 0;
}