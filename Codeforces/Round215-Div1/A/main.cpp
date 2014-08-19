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

const int maxn = 100000 + 5;
int n, m;
string input;
int sum[maxn][3];

int main() {
	cin >> input;
	int n = SZ(input);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			sum[i + 1][j] = sum[i][j] + (input[i] == (char)('x' + j));
		}
	}
	cin >> m;
	while (m--) {
		int l, r;
		cin >> l >> r;
		int mx = 0, mn = maxn;
		for (int j = 0; j < 3; j++) {
			mx = max(mx, sum[r][j] - sum[l - 1][j]);
			mn = min(mn, sum[r][j] - sum[l - 1][j]);
		}
		puts((mx - mn <= 1 || r - l <= 1) ? "YES" : "NO");
	}
	return 0;
}

