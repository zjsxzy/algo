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

const int MOD = 1000000007;
int n, k;
int a[25], bad[25];
int sum[1 << 24], dp[1 << 24];
int main(int argc, char const *argv[])
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cin >> k;
	for (int i = 0; i < k; i++)
		cin >> bad[i];

	sum[0] = 0;
	for (int i = 1; i < (1 << n); i++) {
		int j = __builtin_ctz(i);
		sum[i] = sum[i ^ (1 << j)] + a[j];
	}

	for (int i = 1; i < (1 << n); i++) {
		for (int j = 0; j < k; j++) {
			if (sum[i] == bad[j]) {
				dp[i] = -1;
				break;
			}
		}
	}

	dp[0] = 1;
	for (int i = 1; i < (1 << n); i++) {
		if (dp[i] < 0) {
			dp[i] = 0;
		} else {
			for (int j = 0; j < n; j++) {
				if (i & (1 << j)) {
					dp[i] += dp[i ^ (1 << j)];
					if (dp[i] > MOD) dp[i] -= MOD;
				}
			}
		}
	}
	cout << dp[(1 << n) - 1] << endl;
	return 0;
}