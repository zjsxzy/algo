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

const int MAXN = 55;
const unsigned long long MOD = (unsigned long long)1 << 64;
unsigned long long dp[15][15][15][15][15];
int n;
int cnt[15];
string card[MAXN];
map<char, int> mp;
void prepare() {
	mp['2'] = 1; mp['3'] = 2; mp['4'] = 3; mp['5'] = 4; mp['6'] = 5;
	mp['7'] = 6; mp['8'] = 7; mp['9'] = 8; mp['T'] = 9; mp['J'] = 10;
	mp['Q'] = 11; mp['K'] = 12; mp['A'] = 13;
}
unsigned long long rec(int s1, int s2, int s3, int s4, int v) {
	// cout << s1 << " " << s2 << " " << s3 << " " << s4 << " " << v << endl;
	if (s1 + s2 + s3 + s4 <= 0) return 1;
	if (dp[s1][s2][s3][s4][v] != -1) return dp[s1][s2][s3][s4][v];
	unsigned long long ret = 0;
	if (s1 > 0) {
		ret += rec(s1 - 1, s2, s3, s4, 0) * (unsigned long long)(v == 1 ? s1 - 1 : s1);
		ret %= MOD;
	}
	if (s2 > 0) {
		ret += rec(s1 + 1, s2 - 1, s3, s4, 1) * (unsigned long long)(v == 2 ? s2 - 1 : s2) * 2;
		ret %= MOD;
	}
	if (s3 > 0) {
		ret += rec(s1, s2 + 1, s3 - 1, s4, 2) * (unsigned long long)(v == 3 ? s3 - 1 : s3) * 3;
		ret %= MOD;
	}
	if (s4 > 0) {
		ret += rec(s1, s2, s3 + 1, s4 - 1, 3) * (unsigned long long)(v == 4 ? s4 - 1 : s4) * 4;
		ret %= MOD;
	}
	dp[s1][s2][s3][s4][v] = ret;
	return ret;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	prepare();
	int ts;
	cin >> ts;
	memset(dp, -1, sizeof(dp));
	for (int cas = 1; cas <= ts; cas++) {
		printf("Case #%d: ", cas);
		memset(cnt, 0, sizeof(cnt));
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> card[i];
			cnt[mp[card[i][0]]]++;
		}
		unsigned long long res = 0;
		// for (int i = 1; i <= 13; i++)
		// 	cout << cnt[i] << " ";
		// cout << endl;
		int a = 0, b = 0, c = 0, d = 0;
		for (int j = 1; j <= 13; j++) {
			if (cnt[j] == 1) a++;
			else if (cnt[j] == 2) b++;
			else if (cnt[j] == 3) c++;
			else if (cnt[j] == 4) d++;
		}
		res = rec(a, b, c, d, 0);
		cout << res << endl;
	}
	return 0;
}

