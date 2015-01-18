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

const int MAXN = 4000 + 5;
const LL MOD = 1000000007;
int comb[2][MAXN];
void solve(int n, int m) {
    if (m == 0) {
        cout << 1 << " " << 1 << endl;
        return;
    }
    memset(comb, 0, sizeof(comb));
    comb[0][0] = 1;
    LL ret = 1;
    int iter = 0;
    for (int i = 1; i <= max(n + m, 2 * m - 2); i++) {
		int curr = i % 2, prev = 1 - curr;

		// initialize
		comb[curr][0] = 1;
		for (int j = 1; j <= m; j++) {
			comb[curr][j] = 0;
		}

		for (int j = 1; j <= m; j++) {
			comb[curr][j] = (comb[prev][j] + comb[prev][j - 1]) % MOD;
		}
		if (i == n + m - 1) {
		 	cout << (comb[curr][m] + MOD - comb[curr][m - 1]) % MOD << " ";
		}
        if (i >= m && i <= 2 * m - 2) {
            iter++;
            ret = (ret + comb[curr][iter]) % MOD;
            ret = (ret + MOD - comb[curr][iter - 1]) % MOD;
        }
    }
    cout << ret << endl;
}
int main() {
#ifndef ONLINE_JUDGE
//	freopen("in.txt", "r", stdin);
#endif
    int ts;
    scanf("%d", &ts);
    for (int cas = 1; cas <= ts; cas++) {
        printf("Case #%d: ", cas);
        int n, m;
        scanf("%d-%d", &n, &m);
        solve(n, m);
    }
	return 0;
}

