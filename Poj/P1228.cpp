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
bool onSeg(Point p, Point a, Point b) {
	return sig(cross(p, a, b))==0 && sig(dot(p, a, b))<=0;
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
bool cmp2(const Point &a, const Point &b) {
	return sig(a.y-b.y)!=0 ? a.y<b.y : sig(a.x-b.x)>0;
}

const int maxn = 1005;
Point ps[maxn];
int n;
int ch[maxn];
bool vis[maxn];

int main() {
	int Test;
	scanf("%d", &Test);
	while (Test--) {
		memset(ch, 0, sizeof(ch));
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%lf%lf", &ps[i].x, &ps[i].y);
		}
		if (n < 6) {
			puts("NO");
			continue;
		}
		int m = graham(ps, n, ch);
		if (m == 2) {
			puts("NO");
			continue;
		}
		ch[m] = ch[0];
		memset(vis, false, sizeof(vis));
		for (int i = 0; i < n; i++) {
			bool flag = false;
			for (int j = 0; j < m; j++) {
				if (i == ch[j]) {
					flag = true;
					break;
				}
			}
			if (flag) continue;
			int idx = -1;
			for (int j = 0; j < m; j++) {
				if (onSeg(ps[i], ps[ch[j]], ps[ch[j + 1]])) {
					idx = j;
					break;
				}
			}
			vis[idx] = true;
		}
		bool ans = true;
		for (int i = 0; i < m; i++) {
			if (!vis[i]) {
				ans = false;
				break;
			}
		}
		printf("%s\n", ans ? "YES" : "NO");
	}
	return 0;
}
