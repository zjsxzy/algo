struct Circle {
    Point ori;
    double radius;
 
    Circle() {}
    Circle(Point ort, double radius) : ori(ori), radius(radius) {}
};
const int MAXN = 1005;
int n;
Circle c[MAXN];
struct Arc {
    double st, ed;
 
    Arc() {}
    Arc(double st, double ed) : st(st), ed(ed) {}
    bool operator < (const Arc &pt) const {
        return sig(st - pt.st) !=0 ? sig(st - pt.st) < 0 : sig(ed - pt.ed) < 0;
    }
};
 
Point rotate(const Point &o, double c, double s) {
    return Point(o.x*c-o.y*s, o.y*c+o.x*s);
}
 
void Intersect_2Cricles(const Circle &Ca, const Circle &Cb, Point &pa, Point &pb) {
    double d = dis(Ca.ori, Cb.ori);
    double cosang = (sqr(Ca.radius) + sqr(d) - sqr(Cb.radius)) / (2.0 * Ca.radius * d);
    double sinang = sqrt(1 - cosang * cosang);
    Point S = Cb.ori - Ca.ori;
    pa = rotate(S, cosang, -sinang).resize(Ca.radius) + Ca.ori;
    pb = rotate(S, cosang, sinang).resize(Ca.radius) + Ca.ori;
}
 
double UnionPerimeter_Circle() {
    double ret = 0;
    for (int i = 0; i < n; i++) {
        vector<Arc> vec;
        bool inside = false;
        for (int j = i + 1; j < n; j++) {
            double Dist = dis(c[i].ori, c[j].ori);
            if (sig(c[i].radius - c[j].radius) <= 0 && sig(c[j].radius - c[i].radius - Dist) >= 0) {
                inside = true;
            } else if (sig(c[i].radius - c[j].radius) >= 0 && sig(c[i].radius - c[j].radius - Dist) >= 0) {
                //do nothing
            }else if (sig(c[i].radius + c[j].radius - Dist) > 0) {
                Point pa, pb;
                Intersect_2Cricles(c[i], c[j], pa, pb);
                double st = atan2(pa.y - c[i].ori.y, pa.x - c[i].ori.x);
                double ed = atan2(pb.y - c[i].ori.y, pb.x - c[i].ori.x);
                if (ed > st) vec.PB(Arc(st, ed));
                else {
                    vec.PB(Arc(st, PI));
                    vec.PB(Arc(-PI, ed));
                }
            }
            if (inside) break;
        }
 
        if (inside) continue;
        double cover = 0;
        if (vec.size()) {
            sort(vec.begin(), vec.end());
            cover = vec[0].ed - vec[0].st;
            double last = vec[0].ed;
            for (int i = 1; i < vec.size(); i++) {
                if (vec[i].st > last) {
                    cover += vec[i].ed - vec[i].st;
                    last = vec[i].ed;
                } else if (vec[i].ed > last) {
                    cover += vec[i].ed - last;
                    last = vec[i].ed;
                }
            }
        }
        ret += (2 * PI - cover) * c[i].radius;
    }
    return ret;
}