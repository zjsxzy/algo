//圆与线段交，交点加入ret中
void circle_cross_line(Point a, Point b, Point o, double r, vector<Point> &ret) {
	double x0 = o.x, y0 = o.y;
	double x1 = a.x, y1 = a.y;
	double x2 = b.x, y2 = b.y;
	double dx = x2 - x1, dy = y2 - y1;
	double A = dx * dx + dy * dy;
	double B = 2 * dx * (x1 - x0) + 2 * dy * (y1 - y0);
	double C = sqr(x1 - x0) + sqr(y1 - y0) - sqr(r);
	double delta = B * B - 4 * A * C;
	if (sig(delta) >= 0) {
		double t1 = (-B - my_sqrt(delta)) / (2 * A);
		double t2 = (-B + my_sqrt(delta)) / (2 * A);
		if (sig(t1 - 1) <= 0 && sig(t1) >= 0) {
			ret.PB(Point(x1 + t1 * dx, y1 + t1 * dy));
		}
		if (sig(t2 - 1) <= 0 && sig(t2) >= 0) {
			ret.PB(Point(x1 + t2 * dx, y1 + t2 * dy));
		}
	}
}

//扇形区域面积
double sector_area(Point a, Point b, Point o, double r) {
	double theta = atan2(a.y - o.y, a.x - o.x) - atan2(b.y - o.y, b.x - o.x);
	while (theta <= 0) theta += 2 * PI;
	while (theta > 2 * PI) theta -= 2 * PI;
	theta = min(theta, 2 * PI - theta);
	return r * r * theta / 2;
}

//圆心与线段构成的区域面积
double CircleTrianlge(Point a, Point b, Point o, double radius) {
	vector<Point> p;
	int ina = sig(dis(a, o) - radius) < 0;
	int inb = sig(dis(b, o) - radius) < 0;
	//分四种情况讨论a和b是否在圆内
	if (ina) {
		if (inb) {
			return fabs(cross(o, a, b)) / 2.0;
		} else {
			circle_cross_line(a, b, o, radius, p);
			return sector_area(b, p[0], o, radius) + fabs(cross(o, a, p[0])) / 2.0;
	}
	} else {
		if (inb) {
			circle_cross_line(a, b, o, radius, p);
			return sector_area(p[0], a, o, radius) + fabs(cross(o, p[0], b)) / 2.0;
		} else {
			circle_cross_line(a, b, o, radius, p);
			if (p.size() == 2) {
				return sector_area(a, p[0], o, radius) + sector_area(p[1], b, o, radius) + fabs(cross(o, p[0], p[1]) ) / 2.0;
			} else {
				return sector_area(a, b, o, radius);
			}
		}
	}
}

//圆与一般多边形面积交
double CirclePolygon(Point *ps, int n, Point o, double radius) {
	//保证逆时针
	if (area(ps, n) < 0) reverse(ps, ps + n);

	ps[n] = ps[0];
	double res = 0;
	for (int i = 0; i < n; i++) {
		int sgn = sig(ps[i].x * ps[i + 1].y - ps[i].y * ps[i + 1].x);
		if (sgn != 0) {
			res += sgn * CircleTrianlge(ps[i], ps[i + 1], o, radius);
		}
	}
	return res;
}

const int MAXN = 1000 + 10;
struct Point {
    double x, y;
    Point operator-(Point &it) {
        Point tmp;
        tmp.x = x - it.x;
        tmp.y = y - it.y;
        return tmp;
    }
};
struct Circle {
    double radis;
    Point center;
};
struct Triangle {
    Point t[3];
};
Circle c;
Point a[MAXN];

double dist(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
double triangleArea(Triangle t) {
    Point p1, p2;
    p1 = t.t[1] - t.t[0];
    p2 = t.t[2] - t.t[0];
    return fabs(p1.x * p2.y - p1.y * p2.x) / 2;
}

Circle circumcircleOfTriangle(Triangle t) {
    //三角形的外接圆
    Circle tmp;
    double a, b, c, c1, c2;
    double xA, yA, xB, yB, xC, yC;
    a = dist(t.t[0], t.t[1]);
    b = dist(t.t[1], t.t[2]);
    c = dist(t.t[2], t.t[0]);
    //根据S = a * b * c / R / 4;求半径R
    tmp.radis = a * b * c / triangleArea(t) / 4;

    xA = t.t[0].x, yA = t.t[0].y;
    xB = t.t[1].x, yB = t.t[1].y;
    xC = t.t[2].x, yC = t.t[2].y;
    c1 = (xA * xA + yA * yA - xB * xB - yB * yB) / 2;
    c2 = (xA * xA + yA * yA - xC * xC - yC * yC) / 2;

    tmp.center.x = (c1 * (yA - yC) - c2 * (yA - yB)) / ((xA - xB) * (yA - yC) - (xA - xC) * (yA - yB));
    tmp.center.y = (c1 * (xA - xC) - c2 * (xA - xB)) / ((yA - yB) * (xA - xC) - (yA - yC) * (xA - xB));
    return tmp;
}

Circle MinCircle2(int tce, Triangle ce) {
    Circle tmp;
    if (tce == 0) tmp.radis = -2;
    else if (tce == 1) {
        tmp.center = ce.t[0];
        tmp.radis = 0;
    }
    else if (tce == 2) {
        tmp.radis = dist(ce.t[0], ce.t[1]) / 2;
        tmp.center.x = (ce.t[0].x + ce.t[1].x) / 2;
        tmp.center.y = (ce.t[0].y + ce.t[1].y) / 2;
    }
    else if (tce == 3) tmp = circumcircleOfTriangle(ce);
    return tmp;
}


void MinCircle(int n, int tce, Triangle ce) {
    Point tmp;
    c = MinCircle2(tce, ce);
    if (tce == 3) return;
    for (int i = 1; i <= n; i++) {
        if (dist(a[i], c.center) > c.radis) {
            ce.t[tce] = a[i];
            MinCircle(i - 1, tce + 1, ce);
            tmp = a[i];
            for (int j = i; j >= 2; j--)
                a[j] = a[j - 1];
            a[1] = tmp;
        }
    }
}

