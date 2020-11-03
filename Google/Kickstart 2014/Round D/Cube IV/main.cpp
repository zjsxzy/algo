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
int n;
pair<int, int> pos[MAXN * MAXN];
int dp[MAXN * MAXN];
int dist(pair<int, int> x, pair<int, int> y) {
	return abs(x.first - y.first) + abs(x.second - y.second);
}
int main() {
#ifndef ONLINE_JUDGE
	// freopen("in.txt", "r", stdin);
#endif
	int ts;
	cin >> ts;
	for (int cas = 1; cas <= ts; cas++) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int x;
				cin >> x;
				pos[x] = MP(i, j);
			}
		}
		dp[1] = 1;
		int res = 1, resx = 1;
		for (int i = 2; i <= n * n; i++) {
			// cout << pos[i].first << " " << pos[i].second << endl;
			dp[i] = dist(pos[i], pos[i - 1]) == 1 ? dp[i - 1] + 1 : 1;
			if (dp[i] > res) {
				res = dp[i];
				resx = i - dp[i] + 1;
			}
		}
		printf("Case #%d: %d %d\n", cas, resx, res);
	}
	return 0;
}

