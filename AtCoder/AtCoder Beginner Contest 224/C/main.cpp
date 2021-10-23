#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int maxn = 305;
struct Point {
	LL x, y;
	Point(LL x, LL y) : x(x), y(y) {}
	Point() {}
};

int n;
Point p[maxn];

LL cross(const Point & o, const Point & a, const Point & b) {
	return (a.x-o.x)*(b.y-o.y) - (b.x-o.x)*(a.y-o.y);
}

bool check(int i, int j, int k) {
    if (cross(p[i], p[j], p[k]) == 0) return false;
    return true;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        LL x, y;
        cin >> x >> y;
        p[i] = Point(x, y);
    }
    int res = 0;
    int t = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (check(i, j, k)) res++;
            }
        }
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

