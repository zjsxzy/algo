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

const int maxn = 2005;
const LL mod = 1000000007;
int h, w;
string s[maxn];
LL dp[maxn][maxn], dprs[maxn][maxn], dpcs[maxn][maxn], dpds[maxn][maxn];

int main() {
    cin >> h >> w;
    for (int i = 0; i < h; i++) {
        cin >> s[i];
    }
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (s[i][j] == '#') continue;
            if (i - 1 >= 0) {
                dp[i][j] = (dp[i][j] + dprs[i - 1][j]) % mod;
            }
            if (j - 1 >= 0) {
                dp[i][j] = (dp[i][j] + dpcs[i][j - 1]) % mod;
            }
            if (i - 1 >= 0 && j - 1 >= 0) {
                dp[i][j] = (dp[i][j] + dpds[i - 1][j - 1]) % mod;
            }
            if (i - 1 >= 0) {
                dprs[i][j] = (dprs[i - 1][j] + dp[i][j]) % mod;
            } else {
                dprs[i][j] = dp[i][j];
            }
            if (j - 1 >= 0) {
                dpcs[i][j] = (dpcs[i][j - 1] + dp[i][j]) % mod;
            } else {
                dpcs[i][j] = dp[i][j];
            }
            if (i - 1 >= 0 && j - 1 >= 0) {
                dpds[i][j] = (dpds[i - 1][j - 1] + dp[i][j]) % mod;
            } else {
                dpds[i][j] = dp[i][j];
            }
        }
    }
    cout << dp[h - 1][w - 1] << endl;
    return 0;
}

