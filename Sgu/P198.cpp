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

const int maxn = 305;
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
int n;
Point ps[maxn];
double radius[maxn];
Point s;
double r;
int cnt[maxn];
double adj[maxn][maxn], dist[maxn];
bool vis[maxn], mk[maxn][maxn];

double getAng(const Point &o, const Point &a, const Point &b) {
	return atan2(cross(o, a, b), dot(o, a, b));
}

int main() {
	while (~scanf("%d", &n)) {
		for (int i = 0; i < n; i++) {
			scanf("%lf%lf%lf", &ps[i].x, &ps[i].y, &radius[i]);
		}
		scanf("%lf%lf%lf", &s.x, &s.y, &r);

		memset(adj, 0, sizeof(adj));
		memset(mk, 0, sizeof(mk));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				double d = dis(ps[i], ps[j]);
				if (sig(d - (radius[i] + radius[j] + 2 * r)) < 0) {
					mk[i][j] = true;
					adj[i][j] = getAng(s, ps[i], ps[j]);
					//cout << i << " -> " << j << " " << adj[i][j] << endl;
				}
			}
		}
		memset(dist, 0, sizeof(dist));
		memset(cnt, 0, sizeof(cnt));
		queue<int> q;
		for (int i = 0; i < n; i++) {
			vis[i] = true;
			q.push(i);
		}
		bool flag = true;
		while (!q.empty() && flag) {
			int u = q.front(); q.pop();
			vis[u] = false;
			for (int v = 0; v < n && flag; v++) {
				if (mk[u][v] && sig(dist[u] + adj[u][v] - dist[v]) < 0) {
					dist[v] = dist[u] + adj[u][v];
					if (!vis[v]) {
						cnt[v]++;
						if (cnt[v] > n) {
							puts("NO");
							flag = false;
						}
						vis[v] = true;
						q.push(v);
					}
				}
			}
		}
		if (flag) puts("YES");
	}
	return 0;
}
