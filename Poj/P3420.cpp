#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <bitset>
#include <vector>
#include <cstdio>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;
#define PB push_back
#define MP make_pair
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
#define FOREACH(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
typedef long long LL;

int n, mod;
const int maxn = 16;
const int maxm = 16;
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

Matrix F;

void dfs(int dep, int current, int s1, int s2) {
	if (current == (1 << 4) - 1) {
		F.mat[s1][s2]++;
		return;
	}
	if (s1 & (1 << dep)) {
		dfs(dep + 1, current, s1, s2);
	} else {
		dfs(dep + 1, current | (1 << dep), s1, s2 | (1 << dep));
		if (dep + 1 < 4 && !(s1 & (1 << (dep + 1)))) {
			dfs(dep + 2, current | (1 << dep) | (1 << (dep + 1)), s1, s2);
		}
	}
}

void init() {
	F.init();
	F.n = F.m = 16;

	for (int i = 0; i < 16; i++) {
		dfs(0, i, i, 0);
	}
}

int main() {
	init();
	while (~scanf("%d%d", &n, &mod)) {
		if (n == 0 && mod == 0) break;
		Matrix res;
		res.n = res.m = F.n;
		for (int i = 0; i < res.n; i++) {
			for (int j = 0; j < res.m; j++) {
				res.mat[i][j] = F.mat[i][j] % mod;
			}
		}
		res = res ^ n;
		cout << res.mat[0][0] << endl;
	}
	return 0;
}
