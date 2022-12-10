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

const int MAXN = 305;
int n, m, kk;
LL dp[MAXN][MAXN];
set<int> val[MAXN];
vector<pair<int, int> > fix[MAXN];

int main(int argc, char const *argv[])
{
	cin >> n >> m >> kk;
	for (int i = 0; i < m; i++) {
		int l, r;
		LL cost;
		cin >> l >> r >> cost;
		fix[l].PB(MP(r, cost));
	}

	memset(dp, -1, sizeof(dp));
	dp[0][0] = 0;
	for (int i = 0; i < n; i++) {
		FOREACH(it, fix[i + 1]) {
			val[it->first].insert(it->second);
		}

		for (int j = 0; j <= i; j++) {
			if (dp[i][j] == -1) continue;
			if (dp[i + 1][j] == -1 || dp[i][j] < dp[i + 1][j]) {
				dp[i + 1][j] = dp[i][j];
			}

			for (int k = i + 1; k <= n; k++) {
				if (val[k].size() == 0) continue;
				LL cost = *(val[k].begin());
				if (dp[k][j + k - i] == -1 || dp[i][j] + cost < dp[k][j + k - i])
					dp[k][j + k - i] = dp[i][j] + cost;
			}
		}
	}
	
	LL ret = -1;
	for (int i = 0; i <= n; i++)
		for (int j = kk; j <= n; j++)
			if (ret == -1 || dp[i][j] >= 0 && dp[i][j] < ret)
				ret = dp[i][j];
	cout << ret << endl;

	return 0;
}