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
#include <cassert>
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

const double r = 0.5772156649;
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	vector<double> f;
	f.push_back(1);
	double prev = 1;
	for (int i = 2; ; i++) {
		double cur = prev + 1.0 / i;
		if (cur - prev > 1e-5) {
			f.push_back(cur);
		} else {
			break;
		}
		prev = cur;
	}
	int n;
	while (~scanf("%d", &n)) {
		if (n >= f.size()) {
			printf("%.4f\n", log(n) + r);
		} else {
			printf("%.4f\n", f[n - 1]);
		}
	}
	return 0;
}

