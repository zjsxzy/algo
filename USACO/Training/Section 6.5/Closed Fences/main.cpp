/*
ID: frankzh1
TASK: fence4
LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
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
int n;
vector<Point> fence;

bool isValid() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            Point p;
            if (lineCross(fence[i], fence[(i + 1) % n], fence[j], fence[(j + 1) % n], p)) {
                if (onSeg(p, fence[i], fence[(i + 1) % n]) && onSeg(p, fence[j], fence[(j + 1) % n])) {
                    if (p == fence[i] || p == fence[(i + 1) % n] || p == fence[j] || p == fence[(j + 1) % n]) continue;
                    else return false;
                }
            }
        }
    }
    return true;
}

void solve() {
    cin >> n;
    Point ob;
    cin >> ob.x >> ob.y;
    fence.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> fence[i].x >> fence[i].y;
    }
    if (!isValid()) {
        cout << "NOFENCE" << endl;
        return;
    }
    vector<bool> visited(n);
    for (int i = 0; i < n; i++) {
        Point tmp = fence[i];
        double dx = (fence[(i + 1) % n].x - fence[i].x) / 500;
        double dy = (fence[(i + 1) % n].y - fence[i].y) / 500;
        for (int j = 1; j < 500; j++) {
            tmp.x += dx; tmp.y += dy;
            bool isCovered = false;
            for (int k = 0; k < n; k++) {
                if (i == k) continue;
                Point p;
                if (lineCross(ob, tmp, fence[k], fence[(k + 1) % n], p)) {
                    if (onSeg(p, fence[k], fence[(k + 1) % n]) && onSeg(p, ob, tmp)) {
                        isCovered = true;
                        break;
                    }
                }
            }
            if (!isCovered) {
                visited[i] = true;
                break;
            }
        }
    }
    vector<pair<Point, Point>> ans;
    for (int i = 0; i < n - 2; i++) {
        if (visited[i] && cross(ob, fence[i], fence[i + 1]) != 0) {
            ans.emplace_back(fence[i], fence[i + 1]);
        }
    }
    if (visited[n - 1] && cross(ob, fence[n - 1], fence[0]) != 0) {
        ans.emplace_back(fence[0], fence[n - 1]);
    }
    if (visited[n - 2] && cross(ob, fence[n - 2], fence[n - 1]) != 0) {
        ans.emplace_back(fence[n - 2], fence[n - 1]);
    }
    cout << ans.size() << endl;
    for (auto &p: ans) {
        cout << p.first.x << " " << p.first.y << " " << p.second.x << " " << p.second.y << endl;
    }
}

int main() {
    freopen("fence4.in", "r", stdin);
    freopen("fence4.out", "w", stdout);
    solve();
    return 0;
}

