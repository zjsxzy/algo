#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const LL mod = 998244353;
int N, M, K;
LL dp[55][2555];

void solve() {
    cin >> N >> M >> K;
    dp[0][0] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            if (!dp[i][j]) continue;
            for (int k = 1; k <= M; k++) {
                if (j + k <= K) {
                    dp[i + 1][j + k] += dp[i][j];
                    dp[i + 1][j + k] %= mod;
                }
            }
            // cout << i << " " << j << " " << dp[i][j] << endl;
        }
    }
    LL res = 0;
    for (int k = 1; k <= K; k++) {
        res += dp[N][k];
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

