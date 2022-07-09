#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

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
	Point left90() {
		return Point(-y, x);
	}
	Point rotate(double radian) {	//逆时针转
		double c = cos(radian), s = sin(radian);
		return Point(x*c-y*s, y*c+x*s);
	}
	void output() {
		printf("x = %.2f, y = %.2f\n", x, y);
	}
};

void solve() {
    Point p;
    double d;
    cin >> p.x >> p.y >> d;
    Point res = p.rotate(2.0 * M_PI * d / 360);
    printf("%.9f %.9f\n", res.x, res.y);
}

int main() {
#ifndef ONLINE_JUDGE
   freopen("in.txt", "r", stdin);
#endif
   int ts = 1;
   // cin >> ts;
   for (int t = 1; t <= ts; t++) {
       solve();
   }
   return 0;
}

