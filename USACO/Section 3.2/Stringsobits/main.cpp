#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define SZ(v) ((int)(v).size())
#define abs(x) ((x) > 0 ? (x) : -(x))
typedef long long LL;

const int MAXN = 33;
long long dp[MAXN][MAXN], sumdp[MAXN][MAXN];
vector<int> bits;

void dfs(int x, int l, int p) {
    if (x == 0) {
        return;
    }
    if (p <= sumdp[x - 1][l]) {
        bits.emplace_back(0);
        dfs(x - 1, l, p);
    } else {
        bits.emplace_back(1);
        dfs(x - 1, l - 1, p - sumdp[x - 1][l]);
    }
}

void solve() {
    int n, l;
    long long p;
    cin >> n >> l >> p;
    memset(dp, 0, sizeof(dp));
    memset(sumdp, 0, sizeof(sumdp));
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            sumdp[i][j] = sumdp[i][j - 1] + dp[i][j];
        }
    }
    dfs(n, l, p);
    reverse(bits.begin(), bits.end());
    for (auto &b: bits) {
        cout << b;
    }
    cout << endl;
}

int main() {
    freopen("in.txt", "r", stdin);
    solve();
    return 0;
}

