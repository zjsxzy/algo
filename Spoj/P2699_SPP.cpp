/*
 * 矩阵乘法
 * TLE
 */
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
using namespace std;

typedef long long LL;
struct Matrix {
        int n, m;
        LL mat[16][16];
}F, A, I;
LL M, N, K, mod;
int b[16], c[16];

void initI()
{
	I.n = I.m = K;
	memset(I.mat, 0, sizeof(I.mat));
	for (int i = 0; i < K; i++)
		I.mat[i][i] = 1;
}

void initF() {
	F.n = F.m = K;
    memset(F.mat, 0, sizeof(F.mat));
	for (int i = 1; i < K; i++)
		F.mat[i][i - 1] = 1;
    for (int i = 0; i < K; i++)
		F.mat[i][K - 1] = c[K - i - 1];
}

void initA() {
	A.n = 1; A.m = K;
	memset(A.mat, 0, sizeof(A.mat));
	for (int i = 0; i < K; i++)
		A.mat[0][i] = b[i];
}

Matrix operator + (Matrix a, Matrix b) {
        Matrix c;
        c.n = a.n; c.m = a.m;
        for (int i = 0; i < a.n; i++)
                for (int j = 0; j < a.m; j++) {
                        c.mat[i][j] = (a.mat[i][j] + b.mat[i][j]) % mod;
                }
        return c;
}

Matrix operator*(Matrix a, Matrix b) {
        Matrix c;
        c.n = a.n; c.m = b.m;
        for (int i = 0; i < a.n; i++)
                for (int j = 0; j < b.m; j++) {
                        c.mat[i][j] = 0;
                        for (int k = 0; k < a.m; k++) 
                                c.mat[i][j] = (c.mat[i][j] + a.mat[i][k] * b.mat[k][j]) % mod;
                }
        return c;
}

//矩阵快速幂
Matrix operator^(Matrix A, LL x) {
        Matrix c;
        c = I;
        for (; x; x >>= 1) {
                if (x & 1) c = c * A;
                A = A * A;
        }
        return c;
}

Matrix Sum(int x) {
    if (x == 1) return F;
    if (x & 1) return (F ^ x) + Sum(x - 1);
    else return Sum(x / 2) * ((F ^ (x / 2)) + I);
}

int main()
{
	freopen("in", "r", stdin);
	int Test;
	cin >> Test;
	while (Test--) {
		cin >> K;
		for (int i = 0; i < K; i++)
			cin >> b[i];
		for (int i = 0; i < K; i++)
			cin >> c[i];
		cin >> M >> N >> mod;
		LL ret = 0;
		if (M <= K) {
			for (int i = M; i <= min(K, N); i++) {
				ret += b[i - 1];
				ret %= mod;
			}
			M = K + 1;
		}
		if (N <= K) {
			cout << ret << endl;
			continue;
		}	
		M -= K;
		N -= K;
		initI();
		initA();
		initF();
		Matrix ans = A;
		/*for (int i = M; i <= N; i++) {
			Matrix tmp = A;
			tmp = tmp * (F ^ i);
			cout << tmp.mat[0][K - 1] << endl;
		}*/
		ans = ans * (F ^ (M - 1));
		ans = ans * Sum(N - M + 1);
		ret += ans.mat[0][K - 1];
		ret %= mod;
		cout << ret << endl;
	}
	return 0;
}

