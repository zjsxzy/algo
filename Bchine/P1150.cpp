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

const int maxn = 1000000 + 5;
LL dp[maxn][1 << 4];
int num[4], sum;
int n;

void update(LL &a, LL b) {
	if (a == -1 || b < a) {
		a = b;
	}
}

int main() {
	int ts;
	cin >> ts;
	for (; ts--; ) {
		cin >> n;
		memset(dp, -1, sizeof(dp));
		for (int i = 1; i <= n; i++) {
			sum = 0;
			for (int j = 0; j < 4; j++) {
				cin >> num[j];
				sum += num[j];
			}
			if (i == 1) {
				for (int j = 0; j < 4; j++)
					dp[1][1 << j] = sum - num[j];
			} else {
				for (int mask = 1; mask < (1 << 4); mask++) {
					if (dp[i - 1][mask] == -1) continue;
					for (int j = 0; j < 4; j++) {
						int newmask = mask | (1 << j);
						update(dp[i][newmask], dp[i - 1][mask] + sum - num[j]);
					}
				}
			}
		}

		cout << dp[n][(1 << 4) - 1] << endl;
	}
	return 0;
}

