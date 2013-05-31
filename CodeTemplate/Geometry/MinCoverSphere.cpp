int n;
double x[105], y[105], z[105];
#define sqsum(x, y, z) ((x)*(x) + (y)*(y) + (z)*(z))

int main(int argc, char const *argv[])
{
	while (scanf("%d", &n) && n) {
		for (int i = 0; i < n; i++) {
			scanf("%lf%lf%lf", x + i, y + i, z + i);
		}

		double x0 = 0, y0 = 0, z0 = 0, lambda = 1;
		for (int k = 0; k < 100000; k++) {
			int i_opt;
			double d_opt = -1;
			for (int i = 0; i < n; i++) {
				double d = sqsum(x[i] - x0, y[i] - y0, z[i] - z0);
				if (d_opt < d) {
					d_opt = d;
					i_opt = i;
				}
			}
			x0 += lambda * (x[i_opt] - x0);
			y0 += lambda * (y[i_opt] - y0);
			z0 += lambda * (z[i_opt] - z0);
			lambda *= 0.99;
		}
		double radius = 0;
		for (int i = 0; i < n; i++) {
			double d = sqsum(x[i] - x0, y[i] - y0, z[i] - z0);
			if (radius < d) {
				radius = d;
			}
		}
		printf("%.9f\n", sqrt(radius));
		printf("%.9f %.9f %.9f\n", x0, y0, z0);
	}
	return 0;
}