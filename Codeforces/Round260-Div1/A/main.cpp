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

const int MAXN = 100000 + 5;
int n;
vector<int> a;
int cnt[MAXN];
LL dp[MAXN][2];

int main() {
	scanf("%d", &n);
	a.resize(n);
	memset(cnt, 0, sizeof(cnt));
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		cnt[a[i]]++;
	}
	sort(a.begin(), a.end());
	a.resize(unique(a.begin(), a.end()) - a.begin());
	n = a.size();

	dp[0][0] = 0;
	dp[0][1] = (LL)a[0] * cnt[a[0]];
	for (int i = 1; i < n; i++) {
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
		if (a[i] - a[i - 1] == 1) {
			dp[i][1] = dp[i - 1][0] + (LL)a[i] * cnt[a[i]];
		} else {
			dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]);
			dp[i][1] += (LL)a[i] * cnt[a[i]];
		}
	}
	cout << max(dp[n - 1][0], dp[n - 1][1]) << endl;
	return 0;
}

