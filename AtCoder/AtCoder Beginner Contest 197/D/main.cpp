#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
double my_sqrt(double d) {return sqrt(max(d, 0.0));}
double my_acos(double d) {return acos(d<-1?-1:d>1?1:d);}
#define sqr(v) ((v)*(v))
#define PI		3.14159265358979323846	/* pi */
typedef long long LL;
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
		printf("%.9f %.9f\n", x, y);
	}
};

void solve() {
    double n;
    cin >> n;
    double x0, y0, xn, yn;
    cin >> x0 >> y0 >> xn >> yn;
    Point a(x0, y0), b(xn, yn);
    Point p = b - a;
    double ang = 0.5 * (n - 2) * 180 / n;
    double r = p.mod() * 0.5;
    double len = n * 2 * r * sin(360 / n / 2 * PI / 180) / n;
    //printf("%.5f %.5f %.5f\n", ang, r, len);
    //p.output();
    Point res = p.rotate((360 - ang) * PI / 180).resize(len);
    res = res + a;
    res.output();
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

