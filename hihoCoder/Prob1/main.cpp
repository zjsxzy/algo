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

const int MAXN = 1000000 + 5;
char s[MAXN], str[MAXN << 1];
int dp[MAXN << 1];

int Manchester() {
	int n = strlen(s);
	int j = 0;
	for (int i = 0; i < n; i++) {
		str[j++] = '#';
		str[j++] = s[i];
	}
	str[j++] = '#';
	n = j;

	int res = 0;
	int right = -1, id = -1;
	for (int i = 0; i < n; i++) {
		int r = 1;
		if (right >= i) {
			r = max(r, min(right - i + 1, dp[2 * id - i]));
		}
		while ((i - r + 1 >= 0 && i + r - 1 < n) && str[i - r + 1] == str[i + r - 1])
			r++;
		r--;
		if (i + r - 1 > right) {
			right = i + r - 1;
			id = i;
		}
		dp[i] = r;
		if (r > res) res = r;
	}
	return res - 1;
}

int main() {
	int ts;
	scanf("%d", &ts);
	while (ts--) {
		scanf("%s", s);
		int res = Manchester();
		printf("%d\n", res);
	}
	return 0;
}

