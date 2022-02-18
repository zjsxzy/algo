#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int maxn = 305;
const LL mod = 998244353;
int n, k;
LL dp[maxn][maxn][maxn];
pair<int, int> a[maxn];

void solve() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i].first;
    for (int i = 1; i <= n; i++) cin >> a[i].second;
    sort(a + 1, a + n + 1);
    dp[0][0][n + 1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            for (int v = 1; v <= n + 1; v++) {
                // choose i
                if (j < i && a[i].second < v) {
                    dp[i][j + 1][v] += dp[i - 1][j][v];
                    dp[i][j + 1][v] %= mod;
                }
                // not choose i
                dp[i][j][min(v, a[i].second)] += dp[i - 1][j][v];
                dp[i][j][min(v, a[i].second)] %= mod;
            }
        }
    }
    LL res = 0;
    for (int v = 1; v <= n + 1; v++) {
        res += dp[n][k][v];
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

