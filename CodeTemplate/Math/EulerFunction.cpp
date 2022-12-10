/*
 * Euler Function Fi(x)
 */
int Euler(int n) {
	int ret = 1;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			n /= i;
			ret *= (i - 1);
			while (n % i == 0)
				n /= i, ret *= i;
		}
	}
	if (n > 1) ret *= n - 1;
	return ret;
}

void euler(int n) {
    vector<vector<int>> divisors(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            divisors[j].push_back(i);
        }
    }
    vector<int> phi(n + 1);
    iota(phi.begin(), phi.end(), 0);
    phi[1] = 0;
    for (int i = 2; i <= n; i++) {
        if ((int)divisors[i].size() == 2) {
            for (int j = i; j <= n; j += i) {
                phi[j] /= i;
                phi[j] *= i - 1;
            }
        }
    }
}
