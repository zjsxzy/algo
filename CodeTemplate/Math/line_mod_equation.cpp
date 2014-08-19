//单变元模线性方程
long long line_mod_equation(long long a, long long b, long long n) {
	long long x, y;
	long long d = extend_gcd(a, n, x, y);
	if (b % d == 0) {
		LL r = n / d;
		return (x * (b / d) % r + r) % r;
	}
	return -1;
}