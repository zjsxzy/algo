#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn = 65;
const int maxm = 65;
const int mod = 1e9 + 7;

struct Matrix {
	int n, m;
	LL mat[maxn][maxm];

	void init() {
		n = m = 0;
		memset(mat, 0, sizeof(mat));
	}
	// Matrix operator + (const Matrix &b) const {
	// 	Matrix tmp;
	// 	tmp.n = n; tmp.m = m;
	// 	for (int i = 0; i < n; i++) {
	// 		for (int j = 0; j < m; j++) {
	// 			tmp.mat[i][j] = mat[i][j] + b.mat[i][j];
    //             tmp.mat[i][j] %= mod;
	// 		}
	// 	}
	// 	return tmp;
	// }
	// Matrix operator - (const Matrix &b) const {
	// 	Matrix tmp;
	// 	tmp.n = n; tmp.m = m;
	// 	for (int i = 0; i < n; i++) {
	// 		for (int j = 0; j < m; j++) {
	// 			tmp.mat[i][j] = (mat[i][j] - b.mat[i][j] + mod) % mod;
	// 		}
	// 	}
	// 	return tmp;
	// }
	Matrix operator * (const Matrix &b) const {
		Matrix tmp;
		tmp.init();
		tmp.n = n; tmp.m = b.m;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < b.m; j++) {
				for (int k = 0; k < m; k++) {
					tmp.mat[i][j] = (tmp.mat[i][j] + mat[i][k] * b.mat[k][j] % mod) % mod;
				}
			}
		}
		return tmp;
	}
	Matrix operator ^ (LL x) {
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

void solve() {
    int n;
    LL k;
    cin >> n >> k;
    Matrix A;
    A.init();
    A.n = A.m = n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A.mat[i][j];
        }
    }
    A = A ^ k;
    cout << A.mat[0][n - 1] << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int ts = 1;
    // cin >> ts;
    for (int t = 1; t <= ts; t++) {
        solve();
    }
    return 0;
}