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

int main() {
    int n;
    LL X;
    cin >> n >> X;
    vector<LL> a(n), x(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = n - 1; i >= 0; i--) {
        x[i] = X / a[i];
        X %= a[i];
    }
    // for (int i = 0; i < n; i++) {
        // cout << x[i] << " ";
    // }
    // cout << endl;
    vector<vector<LL> > dp(n + 1, vector<LL>(2));
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            LL xd = x[i] + j;
            if (xd == 0) {
                dp[i + 1][0] += dp[i][j];
            } else if (i + 1 < n && xd == a[i + 1] / a[i]) {
                dp[i + 1][1] += dp[i][j];
            } else {
                dp[i + 1][0] += dp[i][j];
                dp[i + 1][1] += dp[i][j];
            }
        }
        // cout << i << " " << dp[i][0] << " " << dp[i][1] << endl;
    }
    cout << dp[n][0] << endl;
    return 0;
}

