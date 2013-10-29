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

const int maxn = 3005;
int n;
int a[maxn], b[maxn], c[maxn];
int dp[maxn][2];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	for (int i = 1; i <= n; i++) cin >> c[i];

	memset(dp, -1, sizeof(dp));
	dp[1][0] = a[1]; dp[1][1] = b[1];
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 2; j++) {
			if (i == n && j == 1) break;
			if (j == 0) {
				dp[i][j] = max(dp[i - 1][0] + b[i], dp[i - 1][1] + a[i]);
			} else {
				dp[i][j] = max(dp[i - 1][0] + c[i], dp[i - 1][1] + b[i]);
			}
		}
	}
	cout << dp[n][0] << endl;
	return 0;
}
