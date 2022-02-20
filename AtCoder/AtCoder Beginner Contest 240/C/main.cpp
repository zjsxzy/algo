#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int maxn = 100005;
int dp[105][maxn];

void solve() {
    int n, x;
    cin >> n >> x;
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        for (int j = 0; j <= x; j++) {
            if (j - a >= 0) {
                dp[i][j] |= dp[i - 1][j - a];
            }
            if (j - b >= 0) {
                dp[i][j] |= dp[i - 1][j - b];
            }
        }
    }
    if (dp[n][x]) cout << "Yes" << endl;
    else cout << "No" << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    solve();
    return 0;
}

