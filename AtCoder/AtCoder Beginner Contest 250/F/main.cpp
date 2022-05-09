#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

struct Point {
	LL x, y;
	Point(LL x, LL y) : x(x), y(y) {}
	Point() {}
	Point operator - (const Point & p) const {
		return Point(x-p.x, y-p.y);
	}
	Point operator + (const Point & p) const {
		return Point(x+p.x, y+p.y);
	}
	bool operator == (const Point & p) const {
		return x-p.x==0 && y-p.y==0;
	}
	Point left90() {
		return Point(-y, x);
	}
};
LL cross(const Point & o, const Point & a, const Point & b) {
	return (a.x-o.x)*(b.y-o.y) - (b.x-o.x)*(a.y-o.y);
}

void solve() {
    int n;
    cin >> n;
    vector<Point> pts(n);
    for (int i = 0; i < n; i++) {
        cin >> pts[i].x >> pts[i].y;
    }
    LL a = 0;
    for (int i = 1; i < n; i++) {
        a += cross(pts[0], pts[i], pts[(i + 1) % n]);
    }
    LL res = 8e18, b = 0;
    for (int i = 0, j = 1; i < n; i++) {
        while (4 * b < a) {
            b += cross(pts[i], pts[j], pts[(j + 1) % n]);
            j = (j + 1) % n;
            res = min(res, abs(4 * b - a));
        }
        b -= cross(pts[j], pts[i], pts[(i + 1) % n]);
        res = min(res, abs(4 * b - a));
    }
    cout << res << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

