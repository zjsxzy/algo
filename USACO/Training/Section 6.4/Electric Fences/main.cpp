/*
ID: frankzh1
TASK: fence3
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

#define sqr(v) ((v)*(v))
const int maxn = 155;
const double eps = 1E-6;
const double MIN = 0;
const double MAX = 100;
const double inf = 1e9;
double my_sqrt(double d) {return sqrt(max(d, 0.0));}
double my_acos(double d) {return acos(d<-1?-1:d>1?1:d);}
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

struct Segment {
    Point a, b;
};

int n;
Segment seg[maxn];
double ans, ansx, ansy;

//返回o到线段ab的最短距离
double minDis(Point o, Point a, Point b) {
    if (a == b) return dis(o, a);
	if(sig(dot(b, a, o))<0)	return dis(o, b);
	if(sig(dot(a, b, o))<0)	return dis(o, a);
	return fabs(cross(o, a, b)/dis(a, b));
}

double Calc(double x, double y) {
    Point p = Point(x, y);
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += minDis(p, seg[i].a, seg[i].b);
    }
    return sum;
}

double trinary_search_y(double x) {
    double Left, Right;
    double mid, midmid;
    double mid_value, midmid_value;
    Left = MIN; Right = MAX;
    while (Right - Left > eps) {
        mid = (Left + Right) / 2;
        midmid = (mid + Right) / 2;
        mid_value = Calc(x, mid);
        midmid_value = Calc(x, midmid);
        if (mid_value < midmid_value) Right = midmid;
        else Left = mid;
    }
    double sum = Calc(x, Left);
    if (sum < ans) {
        ans = sum;
        ansx = x;
        ansy = Left;
    }
    return sum;
}

void trinary_search_x() {
    double Left, Right;
    double mid, midmid;
    double mid_value, midmid_value;
    Left = MIN; Right = MAX;
    while (Right - Left > eps) {
        mid = (Left + Right) / 2;
        midmid = (mid + Right) / 2;
        mid_value = trinary_search_y(mid);
        midmid_value = trinary_search_y(midmid);
        if (mid_value < midmid_value) Right = midmid;
        else Left = mid;
    }
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> seg[i].a.x >> seg[i].a.y >> seg[i].b.x >> seg[i].b.y;
    }
    ans = inf;
    trinary_search_x();
    printf("%.1f %.1f %.1f\n", ansx, ansy, ans);
}

int main() {
    freopen("fence3.in", "r", stdin);
    freopen("fence3.out", "w", stdout);
    solve();
    return 0;
}

