#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

#define maxn 1005
struct Point {
	LL x, y;
	Point(LL x, LL y) : x(x), y(y) {}
	Point() {}
};
LL cross(const Point & o, const Point & a, const Point & b) {
	return (a.x-o.x)*(b.y-o.y) - (b.x-o.x)*(a.y-o.y);
}

Point ps[maxn];
int n;

LL area(Point * p, int n) {
	LL res = 0;
	p[n] = p[0];
	for(int i = 0; i < n; i ++) {
        res += cross(p[0], p[i], p[i+1]);
	}
	return abs(res);
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> ps[i].x >> ps[i].y;
    LL res = area(ps, n);
    cout << res << endl;
}

int main() {
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}