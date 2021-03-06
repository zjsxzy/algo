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

const int MOD = 1000000007;
const int MAXN = 1000 + 5;
int n;
int p[MAXN], dp[MAXN];

void add(int &a, int b) {
	a += b;
	if (a >= MOD) a -= MOD;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> p[i];
	int ret = 0;
	for (int i = 1; i <= n; i++) {
		dp[i] = 0;
		for (int j = p[i]; j < i; j++) {
			add(dp[i], dp[j]);
		}
		add(dp[i], 2);
		add(ret, dp[i]);
	}
	cout << ret << endl;
	return 0;
}

