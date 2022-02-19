#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const double eps = 1e-6;
struct point {
    double x, y;
    point() {}
    point(double _x, double _y) {
        x = _x;
        y = _y;
    }
};

LL dist2(LL x1, LL y1, LL x2, LL y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

double dist(double x1, double y1, double x2, double y2){
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

//计算圆心
point f(point& a, point& b, double r){
    //算中点
    point mid((a.x + b.x) / 2.0,(a.y + b.y) / 2.0);
    //AB距离的一半
    double d = dist(a.x, a.y, mid.x, mid.y);
    //计算h
    double h = sqrt(r * r - d * d);
    //计算垂线
    point ba(b.x - a.x, b.y - a.y);
    point hd(-ba.y, ba.x);
    double len = sqrt(hd.x * hd.x + hd.y * hd.y);
    hd.x /= len, hd.y /= len;
    hd.x *= h, hd.y *= h;
    return point(hd.x + mid.x, hd.y + mid.y);
}

void solve() {
    LL x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    LL d = dist2(x1, y1, x2, y2);
    if (d > 20) {
        cout << "No" << endl;
    } else {
        point a, b;
        a.x = x1; a.y = y1;
        b.x = x2; b.y = y2;
        point c = f(a, b, sqrt(5));
        if (abs(c.x - round(c.x)) < eps && abs(c.y - round(c.y) < eps)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

