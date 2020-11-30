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
char dp[MAXN][MAXN];
int pw[MAXN];
int n, k;
string s;
// map<pair<int, int>, char> f;

char win(char a, char b) {
	if (a == b) return a;
	if (a == 'R' && b == 'P') return 'P';
	if (a == 'P' && b == 'S') return 'S';
	if (a == 'S' && b == 'R') return 'R';
	return a;
}

char dfs(int i, int j) {
	if (dp[i][j] != '!') return dp[i][j];
	//if (f.find({i, j}) != f.end()) {
	//	return f[{i, j}];
	//}
	if (j == 0) {
		return s[i];
	}
	char l = dfs(i, j - 1);
	char r = dfs((i + pw[j - 1]) % n, j - 1);
	char res = win(l, r);
	//f[{i, j}] = res;
	dp[i][j] = res;
	return res;
}

void solve() {
    cin >> n >> k;
    cin >> s;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			dp[i][j] = '!';
		}
	}
	pw[0] = 1;
	for (int i = 1; i <= k; i++) {
		pw[i] = pw[i - 1] * 2 % n;
	}
	char res = dfs(0, k);
	cout << res << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

