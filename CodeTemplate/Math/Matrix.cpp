struct Matrix {
	int n, m;
	LL mat[maxn][maxm];

	void init() {
		n = m = 0;
		memset(mat, 0, sizeof(mat));
	}
	Matrix operator + (const Matrix &b) const {
		Matrix tmp;
		tmp.n = n; tmp.m = m;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				tmp.mat[i][j] = mat[i][j] + b.mat[i][j];
			}
		}
		return tmp;
	}
	Matrix operator - (const Matrix &b) const {
		Matrix tmp;
		tmp.n = n; tmp.m = m;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				tmp.mat[i][j] = mat[i][j] - b.mat[i][j];
			}
		}
		return tmp;
	}
	Matrix operator * (const Matrix &b) const {
		Matrix tmp;
		tmp.init();
		tmp.n = n; tmp.m = b.m;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < b.m; j++) {
				for (int k = 0; k < m; k++) {
					tmp.mat[i][j] = (tmp.mat[i][j] + mat[i][k] * b.mat[k][j]) % mod;
				}
			}
		}
		return tmp;
	}
	Matrix operator ^ (int x) {
		Matrix res, p = *this;
		res.init();
		res.n = res.m = n;
		for (int i = 0; i < n; i++)
			res.mat[i][i] = 1;
		for (; x; x >>= 1) {
			if (x & 1) res = res * p;
			p = p * p;
		}
		return res;
	}
	void output() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << mat[i][j] << " ";
			}
			cout << endl;
		}
	}
};

//Calculating F+F^2+...+F^x
Matrix Sum(int x) {
    if (x == 1) return F;
    if (x & 1) return (F ^ x) + Sum(x - 1);
    else return Sum(x / 2) * ((F ^ (x / 2)) + I);
}
