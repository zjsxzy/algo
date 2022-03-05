#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const LL mod = 998244353;
const int maxn = 1000005;
int n;
LL dp[maxn][10];

void solve() {
    cin >> n;
    for (int x = 1; x < 10; x++) {
        dp[1][x] = 1;
    }
    for (int i = 2; i <= n; i++) {
        for (int x = 1; x < 10; x++) {
            for (int d = -1; d <= 1; d++) {
                if (x + d > 0 && x + d < 10) {
                    dp[i][x] += dp[i - 1][x + d];
                    dp[i][x] %= mod;
                }
            }
        }
    }
    LL res = 0;
    for (int x = 1; x < 10; x++) {
        res += dp[n][x];
        res %= mod;
    }
    cout << res << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

