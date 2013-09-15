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

const int mod = 1000000007;
int N, K;
LL dp[20][1 << 20];
int pos[20];

int main() {
	int Test;
	scanf("%d", &Test);
	while (Test--) {
		scanf("%d%d", &N, &K);
		memset(dp, 0, sizeof(dp));
		int mask = 0;
		for (int i = 0; i < K; i++) {
			scanf("%d", &pos[i]);
			mask |= (1 << pos[i]);
		}

		if (K == 0) {
			for (int i = 0; i < N; i++) {
				dp[i][1 << i] = 1;
			}
		} else {
			dp[pos[K - 1]][mask] = 1;
		}

		for (int st = mask; st < (1 << N); st++) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if ((st & (1 << j)) || abs(i - j) == 1) continue;
					dp[j][st | (1 << j)] += dp[i][st];
					dp[j][st | (1 << j)] %= mod;
				}
			}
		}

		LL res = 0;
		for (int i = 0; i < N; i++) {
			res = (res + dp[i][(1 << N) - 1]) % mod;
		}
		cout << res << endl;
	}
}
