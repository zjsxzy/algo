#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int MAXN = 5005;
const int mod = 998244353;
LL comb[MAXN][MAXN];
LL dp[30][MAXN];
int cnt[30];

void init(int n) {
    memset(comb, 0, sizeof(comb));
    for (int i = 0; i <= n; i++) {
        comb[i][0] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % mod;
        }
    }
}

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    init(n);
    for (auto c: s) {
        cnt[c - 'a' + 1]++;
    }
    dp[0][0] = 1;
    for (int i = 1; i <= 26; i++) {
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k <= min(j, cnt[i]); k++) {
                dp[i][j] += dp[i - 1][j - k] * comb[j][k];
                dp[i][j] %= mod;
            }
        }
    }
    LL res = 0;
    for (int j = 1; j <= n; j++) {
        res = (res + dp[26][j]) % mod;
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

