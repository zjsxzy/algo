struct Circle {
	Point ori;
	double radius;

	Circle() {}
	Circle(Point ort, double radius) : ori(ori), radius(radius) {}

	bool operator < (const Circle &pt) const {
		return radius > pt.radius;
	}

	void output() {
		printf("ori.x = %.3f ori.y = %.3f radius = %.3f\n", ori.x, ori.y, radius);
	}
};
const int MAXN = 1005;
int n;
Circle c[MAXN], cir[MAXN];
struct Arc {
	Point pst, ped;
	double st, ed;

	Arc() {}
	Arc(Point pst, Point ped, double st, double ed) : pst(pst), ped(ped), st(st), ed(ed) {}
	bool operator < (const Arc &pt) const {
		return sig(st - pt.st) != 0 ? sig(st - pt.st) < 0 : sig(ed - pt.ed) < 0;
	}
};

Point rotate(const Point &o, double c, double s) {
	return Point(o.x*c-o.y*s, o.y*c+o.x*s);
}

void Intersect_2Cricles(const Circle &Ca, const Circle &Cb, Point &pa, Point &pb) {
	double d = dis(Ca.ori, Cb.ori);
	double cosang = (sqr(Ca.radius) + sqr(d) - sqr(Cb.radius)) / (2.0 * Ca.radius * d);
	if (cosang < -1 || cosang > 1) {
		Circle a = Ca, b = Cb;
		printf("d = %.3f %.3f\n", d, Ca.radius - Cb.radius);
		a.output();
		b.output();
		printf("%.5f\n", cosang);
	}
	double sinang = sqrt(1 - cosang * cosang);
	Point S = Cb.ori - Ca.ori;
	pa = rotate(S, cosang, -sinang).resize(Ca.radius) + Ca.ori;
	pb = rotate(S, cosang, sinang).resize(Ca.radius) + Ca.ori;
}

void prepare() {
	sort(c, c + n);
	int m = 0;
	for (int i = 0; i < n; i++) {
		if (c[i].radius == 0) break;
		bool inside = false;
		for (int j = 0; j < m; j++) {
			if (sqr(dis(c[i].ori, cir[j].ori)) <= sqr(cir[j].radius - c[i].radius)) {
				inside = true;
				break;
			}
		}
		if (inside) continue;
		cir[m++] = c[i];
	}
	n = m;
	memcpy(c, cir, sizeof(cir));
}

double UnionArea_Circle() {
	double ret = 0;
	for (int i = 0; i < n; i++) {
		vector<Arc> vec;
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			if (sig(dis(c[i].ori, c[j].ori) - (c[i].radius + c[j].radius) >= 0)) continue;
			Point pa, pb;
			Intersect_2Cricles(c[i], c[j], pa, pb);
			double st = atan2(pa.y - c[i].ori.y, pa.x - c[i].ori.x);
			double ed = atan2(pb.y - c[i].ori.y, pb.x - c[i].ori.x);
			if (ed > st) {
				vec.PB(Arc(pa, pb, st, ed));
			} else {
				vec.PB(Arc(pa, c[i].ori - Point(c[i].radius, 0), st, PI));
				vec.PB(Arc(c[i].ori - Point(c[i].radius, 0), pb, -PI, ed));
			}
		}

		if (vec.size() != 0) {
			sort(vec.begin(), vec.end());
			double last = vec[0].ed;
			Point p = vec[0].ped, q;
			for (int j = 0; j < vec.size(); j++) {
				if (vec[j].st < last) {
					if (vec[j].ed > last) {
						last = vec[j].ed;
						p = vec[j].ped;
					}
				} else {
					double ang = vec[j].st - last;
					ret += 0.5 * sqr(c[i].radius) * (ang - sin(ang));
					q = vec[j].pst;
					ret += (p.x * q.y - p.y * q.x) / 2;
					last = vec[j].ed;
					p = vec[j].ped;
				}
			}
			double ang = 2.0 * PI - last + vec[0].st;
			ret += 0.5 * sqr(c[i].radius) * (ang - sin(ang));
			q = vec[0].pst;
			ret += (p.x * q.y - p.y * q.x) / 2;
		} else {
			ret += PI * sqr(c[i].radius);
		}
	}
	return ret;
}
