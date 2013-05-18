pair<pair<int, int>, double> close0(TPoint *ps, int l, int r) {
	if (r - l <= 1) return MP(MP(-1, -1), 1e100);
	pair<pair<int, int>, double> ret;
	ret.second = 1e100;
	int m = (l + r) / 2, i;
	for (i = m; i >= l && sig(ps[i].x - ps[m].x) == 0; i--);
	pair<pair<int, int>, double> temp = close0(ps, l, i + 1);
	if (temp.second < ret.second) {
		ret = temp;
	}
	for (i = m; i < r && sig(ps[i].x - ps[m].x) == 0; i++);
	temp = close0(ps, i, r);
	if (temp.second < ret.second) {
		ret = temp;
	}
	int len = 0;
	for (i = m; i >= l && sig(ps[m].x - ret.second - ps[i].x) < 0; i--) {
		psy[len++] = ps[i];
	}
	for (i = m + 1; i < r && sig(ps[m].x + ret.second - ps[i].x) > 0; i++) {
		psy[len++] = ps[i];
	}
	sort(psy, psy + len, cmp_y);
	for (i = 0; i < len; i++)
		for (int j = i + 1; j < len && psy[j].y < psy[i].y + ret.second; j++) {
			double d = dist(psy[i], psy[j]);
			if (d < ret.second) {
				ret.first = MP(psy[i].id, psy[j].id);
				ret.second = d;
			}
		}
	return ret;
}
