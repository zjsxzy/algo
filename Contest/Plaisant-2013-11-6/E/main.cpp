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
#define PB push_back
#define MP make_pair
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
#define FOREACH(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
typedef long long LL;
typedef long double LD;

const int maxn = 200 + 1;
const int maxk = 20 + 1;
LD E[maxn + 1][maxk + 1];
//LD P[maxn + 1][maxk + 1][maxn + 1][maxk + 1];
LD P[maxn + 1][maxk + 1];

void init() {
	for (int n = 0; n <= maxn; n++) {
		E[n][0] = n;
		if (n <= maxk)
			E[n][n] = 0;
	}
	for (int n = 1; n <= maxn; n++) 
	for (int k = 1; k <= n && k <= maxk; k++) {
		memset(P, 0, sizeof(P));
		P[0][0] = 1.0;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= i && j <= k; j++) {
				if (i - 1 >= j && n - k - (i - 1 - j) >= 0)
					P[i][j] = P[i - 1][j] * (n - k - (i - 1 - j)) / (n - (i - 1)); 
				if (j >= 1)
					P[i][j] += P[i - 1][j - 1] * (k - (j - 1)) / (n - (i - 1));
			}
		}

		E[n][k] = 0.0;
		for (int i = 0; i <= n; i++) {
			LD tmp = 0.0;
			for (int j = 0; j <= i && j <= k; j++) {
				tmp = tmp + P[i][j] * E[max(k - j, n - i - (k - j))][k - j];
			}
			E[n][k] = max(E[n][k], tmp);
		}
	}
}
int main() {
	init();
	int n, k;
	while (~scanf("%d %d", &n, &k)) {
		n -= k;
		if (n <= k) {
			cout << 0 << endl;
			continue;
		}
		cout.precision(13);
		cout << E[n][k] << endl;
	}
}
