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

const int INF = 0x3f3f3f3f;
const int maxn = 8, MAX_POWER = 1000 * maxn, MAX_LEVEL = 10;
int n, totalCoin, maxLevel[maxn], initLevel[maxn];
int power[maxn][MAX_LEVEL+1], upCost[maxn][MAX_LEVEL+1];
int dp[MAX_POWER + 10];

int main() {
    int test; scanf("%d", &test);
    for (int ti = 1; ti <= test; ti++) {
        scanf("%d %d", &totalCoin, &n);
        int initPower = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d %d", maxLevel + i, initLevel + i);
            for (int j = 1; j <= maxLevel[i]; j++)
                scanf("%d", power[i] + j);
            initPower += power[i][initLevel[i]];
            for (int j = maxLevel[i]; j >=1; j--) {
                // use diff power
                if (j <= initLevel[i]) power[i][j] = 0;
                else power[i][j] -= power[i][initLevel[i]];
                // printf("power %d,%d,%d\n", i, j, power[i][j]);
            }
            upCost[i][0] = 0;
            for (int j = 1; j <= maxLevel[i] - 1; j++) {
                scanf("%d", upCost[i] + j);
                if (j < initLevel[i]) upCost[i][j] = 0;
                else upCost[i][j] += upCost[i][j-1];
                // printf("upCost %d,%d,%d\n", i, j, upCost[i][j]);
            }
        }
        memset(dp, 0x3f, sizeof(dp));
        dp[0] = 0;
        int maxPower = 1000 * n;
        for (int i = 0; i < n; i++)
        for (int p = maxPower; p >= 0; p--)
        for (int j = initLevel[i] + 1; j <= maxLevel[i]; j++)
        if (p >= power[i][j])
        if (dp[p - power[i][j]] != INF) {
            int upd = dp[p - power[i][j]] + upCost[i][j - 1];
            if (upd <= totalCoin)
                dp[p] = min(dp[p], upd);
        }

        int res = 0;
        for (int p = maxPower; p >= 0; p--)
            if (dp[p] <= totalCoin) {
                res = initPower + p;
                break;
            }
        // debug
        // printf("init: %d, coin=%d\n", initPower, dp[res-initPower]);
        printf("Case #%d: %d\n", ti, res);
    }
}
