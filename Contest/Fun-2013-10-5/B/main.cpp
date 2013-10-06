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

int main() {
	int n, m;
	while (~scanf("%d%d", &n, &m)) {
		if (n == 0 && m == 0) break;
		vector<int> A(n);
		for (int i = 0; i < n; i++)
			scanf("%d", &A[i]);
		sort(A.begin(), A.end());

		vector<double> p(n - m + 1);
		p[0] = 1.0 * m / n;
		for (int i = 1; i <= n - m; i++) {
			p[i] = p[i - 1] * (n - m - i + 1) / (n - i);
		}
		double res = 0;
		for (int i = 0; i <= n - m; i++) {
			res += A[n - i - 1] * p[i];
			res -= A[i] * p[i];
		}
		printf("%.3f\n", res);
	}
	return 0;
}
