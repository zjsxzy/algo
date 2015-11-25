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
const int MOD = 100007;
int dp[MAXN][MAXN];
string str;
int n;
int dpRec(int l, int r) {
	if (dp[l][r] != -1) return dp[l][r];
	if (l == r) {
		return dp[l][r] = 1;
	}
	if (l + 1 == r) {
		if (str[l] == str[r]) dp[l][r] = 3;
		else dp[l][r] = 2;
		return dp[l][r];
	}
	dp[l][r] = 0;
	if (str[l] == str[r]) dp[l][r] = dpRec(l + 1, r - 1) + 1;
	dp[l][r] += dpRec(l + 1, r) + dpRec(l, r - 1) - dpRec(l + 1, r - 1);
	dp[l][r] %= MOD;
	if (dp[l][r] < 0) dp[l][r] += MOD;
	return dp[l][r];
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int ts;
	cin >> ts;
	for (int cas = 1; cas <= ts; cas++) {
		printf("Case #%d: ", cas);
		cin >> str;
		n = str.size();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				dp[i][j] = -1;
			}
		}
		cout << dpRec(0, n - 1) << endl;
	}
	return 0;
}

