/*
ID: frankzh1
TASK: fc
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int maxn = 100005;
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
Point p[maxn];
int idx[maxn];

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p[i].x >> p[i].y;
    }
    int m = graham(p, n, idx);
    double res = 0.0;
    for (int i = 1; i < m; i++) {
        res += dis(p[idx[i]], p[idx[i - 1]]);
    }
    res += dis(p[idx[0]], p[idx[m - 1]]);
    printf("%.2f\n", res);
}

int main() {
    freopen("fc.in", "r", stdin);
    freopen("fc.out", "w", stdout);
    solve();
    return 0;
}

