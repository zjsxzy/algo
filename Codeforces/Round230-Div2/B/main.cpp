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
#include <climits>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define PB push_back
#define MP make_pair
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
#define FOREACH(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
typedef long long LL;

const int MAXN = 175;
int W[MAXN][MAXN];
double A[MAXN][MAXN], B[MAXN][MAXN];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> W[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			double x = W[i][j], y = W[j][i];
			A[i][j] = (x + y) / 2;
			B[i][j] = x - A[i][j];
			if (fabs(B[i][j]) < 1e-8) B[i][j] = 0;
			if (fabs(A[i][j]) < 1e-8) A[i][j] = 0;
			A[j][i] = A[i][j];
			B[j][i] = -B[i][j];
			if (fabs(B[j][i]) < 1e-8) B[i][j] = 0;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%.8f%c", A[i][j], j == n - 1 ? '\n' : ' ');
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%.8f%c", B[i][j], j == n - 1 ? '\n' : ' ');
		}
	}
	return 0;
}

