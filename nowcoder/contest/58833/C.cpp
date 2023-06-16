#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

#define maxn 100010
// #define M_PI		3.14159265358979323846	/* pi */
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
bool onSeg(Point p, Point a, Point b) {
	return sig(cross(p, a, b))==0 && sig(dot(p, a, b))<=0;
}


Point ps[maxn];

bool cmp(const Point& a, const Point& b) {
    return (a.y + eps) / (a.x + eps) < (b.y + eps) / (b.x + eps);
}

void solve() {
    double n, m;
    int k;
    cin >> n >> m >> k;
    Point A(0, 0), B(n, 0), C(n, m), D(0, m);
    for (int i = 0; i < k; i++) {
        cin >> ps[i].x >> ps[i].y;
    }
    double res = 0;
    res = max(res, min(m, ps[0].x) / 2);
    res = max(res, min(m, n - ps[k - 1].x) / 2);
    sort(ps, ps + k, cmp);
    auto solve = [&](Point s, Point t) {
        Point a = Point((s.x + t.x) / 2, (s.y + t.y) / 2);
        Point b = a + (t - s).left90();
        a.output();
        // b.output();
        Point ab, bc, cd, da;
        lineCross(a, b, A, B, ab);
        // ab.output();
        // cout << dis(ab, a) << endl;
        lineCross(a, b, B, C, bc);
        // bc.output();
        lineCross(a, b, C, D, cd);
        // cd.output();
        // cout << dis(cd, a) << endl;
        lineCross(a, b, D, A, da);
        // da.output();
        if (onSeg(ab, A, B) && onSeg(bc, B, C)) {
            return (n - ab.x) * bc.y / (n - ab.x + bc.y);
        }
        if (onSeg(bc, B, C) && onSeg(cd, C, D)) {
            return (m - bc.y) * (n - cd.x) / (m - bc.y + n - cd.x);
        }
        if (onSeg(cd, C, D) && onSeg(da, D, A)) {
            return cd.x * (m - da.y) / (cd.x + m - da.y);
        }
        if (onSeg(da, D, A) && onSeg(ab, A, B)) {
            return da.y * ab.x / (da.y + ab.x);
        }
        if (onSeg(ab, A, B) && onSeg(cd, C, D)) {
            // cout << dis(a, cd) << ' ' << dis(a, ab) << ' ' << dis(a, s) << ' ' << dis(a, t) << endl;
            // cout << dis(s, cd) / 2 * dis(s, cd) / dis(a, cd) << endl;
            // cout << dis(s, ab) / 2 * dis(s, ab) / dis(a, ab) << endl;
            double ang = asin(dis(s, a) / dis(s, cd));
            cout << dis(s, cd) * sin(ang / 2) << endl;
            return dis(s, cd) * sin(ang / 2);
        }
        return 0.0;
    };
    for (int i = 1; i < k; i++) {
        res = max(res, dis(ps[i - 1], ps[i]) / 2);
        res = max(res, solve(ps[i - 1], ps[i]));
    }
    printf("%.9f\n", res);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}