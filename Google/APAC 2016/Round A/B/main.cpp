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

const int MAXN = 1000 + 5;
int n, m;
int a[MAXN];
double sum[MAXN];
int main() {
#ifndef ONLINE_JUDGE
	// freopen("in.txt", "r", stdin);
#endif
	int ts;
	cin >> ts;
	for (int cas = 1; cas <= ts; cas++) {
		printf("Case #%d:\n", cas);
		cin >> n >> m;
		sum[0] = 0.0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			sum[i] = sum[i - 1] + log(a[i]);
		}
		while (m--) {
			int l, r;
			cin >> l >> r;
			l++; r++;
			double s = sum[r] - sum[l - 1];
			double res = exp(s / (r - l + 1));
			printf("%.9f\n", res);
		}
	}
	return 0;
}

