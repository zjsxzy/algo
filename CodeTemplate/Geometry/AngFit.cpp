double fit(double angle) {
	if (sig(angle) < 0) return angle += 2.0 * PI;
	if (sig(angle - 2.0 * PI) > 0) return angle -= 2.0 * PI;
	return angle;
}