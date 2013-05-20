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

const int MAXN = 105;
const int MOD = 1000000007;
int n;
LL a[MAXN], s[MAXN], comb[MAXN * MAXN][MAXN];
LL dp[MAXN][MAXN * MAXN];

void prepare() {
	memset(comb, 0, sizeof(comb));
	comb[0][0] = 1;
	for (int i = 1; i <= 10000; i++) {
		comb[i][0] = 1;
		for (int j = 1; j <= 100; j++) {
			comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % MOD;
		}
	}
}

int main(int argc, char const *argv[])
{
	prepare();
	for (int cas = 1; ~scanf("%d", &n); cas++) {
		memset(s, 0, sizeof(s));
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= n; i++) {
			scanf("%lld", &a[i]);
			s[i] = s[i - 1] + a[i];
		}
		for (int i = 1; i <= n; i++) {
			dp[i][0] = 1;
		}
		for (int j = 1; j <= s[1]; j++) {
			dp[1][j] = 1;
		}
		for (int i = 2; i <= n; i++) {
			for (int j = 1; j <= s[i]; j++) {
				dp[i][j] = dp[i - 1][j];
				for (int k = 1; k <= min((LL)j, a[i]); k++) {
					dp[i][j] = (dp[i][j] + dp[i - 1][j - k] * comb[j][k]) % MOD;
				}
			}
		}
		LL ret = 0;
		for (int j = 1; j <= s[n]; j++) {
			ret = (ret + dp[n][j]) % MOD;
		}
		printf("Case %d: %lld\n", cas, ret);
	}
	return 0;
}