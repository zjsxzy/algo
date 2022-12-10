#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

#define maxn 1010
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
//判断p是否在线段ab上，在端点处也返回true
bool onSeg(Point p, Point a, Point b) {
	return sig(cross(p, a, b))==0 && sig(dot(p, a, b))<=0;
}
/**
 * 判断点p是否在任意多边形ps中
 * 0外，1内，2边上
 */
int inPolygon(Point * ps, int n, Point p) {
	int cnt = 0;
	ps[n] = ps[0];
	for(int i = 0; i < n; i ++) {
		if(onSeg(p, ps[i], ps[i+1]))	return 2;
		int k = sig( cross(ps[i], ps[i+1], p) );
		int d1 = sig( ps[i+0].y-p.y );
		int d2 = sig( ps[i+1].y-p.y );
		if(k>0 && d1<=0 && d2>0)	cnt ++;
		if(k<0 && d2<=0 && d1>0)	cnt --;
	}
	return cnt != 0;
}

Point ps[maxn];
void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> ps[i].x >> ps[i].y;
    }
    for (int i = 0; i < m; i++) {
        Point p;
        cin >> p.x >> p.y;
        int ans = inPolygon(ps, n, p);
        if (ans == 0) cout << "OUTSIDE" << endl;
        else if (ans == 1) cout << "INSIDE" << endl;
        else cout << "BOUNDARY" << endl;
    }
}

int main() {
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}