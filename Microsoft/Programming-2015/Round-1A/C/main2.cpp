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
int num[MAXN], dp[MAXN];
set<int> prime;
bool vst[555555];
void getPrime() {
	memset(vst, false, sizeof(vst));
	for (int i = 2; i <= 500000; i++) {
		if (!vst[i]) {
			prime.insert(i);
			for (int j = 2; i * j <= 500000; j++) {
				vst[i * j] = true;
			}
		}
	}
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	getPrime();
	int ts;
	scanf("%d", &ts);
	for (int cas = 1; cas <= ts; cas++) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", num + i);
		}
		
		memset(dp, 0, sizeof(dp));
		sort(num, num + n);
		dp[0] = 1;
		int res = 1;
		for (int i = 1; i < n; i++) {
			int temp = 0;
			for (int j = 0; j < i; j++) {
				if (num[i] % num[j] != 0 || (num[i] % num[j] == 0 && prime.find(num[i] / num[j]) == prime.end())) {
					if (temp < dp[j]) {
						temp = dp[j];
					}
				}
			}
			dp[i] = temp + 1;
			if (dp[i] > res) res = dp[i];
		}
		printf("Case #%d: %d\n", cas, res);
	}
	return 0;
}

